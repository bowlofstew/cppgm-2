


set config_tcl {

  set myfolder            [pwd] 
  set calibre_source      [fileread "$myfolder/csh.calibre.everest.2015.2_33.2508"]
  set arcx_config         [fileread "$myfolder/arcx.2508.cfg"]
  set dir_map_v2g         [fileread "$myfolder/dir_map_v2g"]


  set calibration_script  {
      #!/bin/csh -f
      setenv XCAL_FINFET_CAL_DIR "/mtr_n10/mtr10_41505/PE003050/from_TSMC/0622_v0.9_qc_calibration/xact_techfile_2_mentor"
      setenv XCAL_INTRINSIC_SUBTRACT_ALL on
      setenv XCAL_DISABLE_ENCRYPT on
      setenv PEX_FS_THREAD 6
      setenv XCAL_NO_M0_STI_TRIM on
    
      xcalibrate -exec -xact3d -remote mtr10_3,mtr10_4,mtr10_5,mtr10_6,mtr10_7 adari.mipt >& log.xcalibrate

      cat rules.FS rules.xact > rules
      rm calibration.db
      rm -rf models process mtr10*.log
  }


  set qa_script {
      #!/bin/csh -f
      Arcx -p arcx.cfg -c 1014 1021 -O Q_EFFRES NO -nt 8 >& arcx.log

      # cd N10FF_v0.1_CORE_run
      # ./run_csh_sge >& log.sge
      # cd ../

      ./run_csh_sge_qsub >& log.sge

      find . -maxdepth 5 -name svdb | xargs rm -rf
  }


  # set exp_names  {                                        g0        g1        g2          }
  # set exp_props  {                                                                                
  #                  { n_gpoly_srm.rsd_enclosure           -0.0076   -0.007    -0.007   }   
  #                  { n_gpoly_srm.rsd_spacing              0.0115    0.0115    0.0115  }
  #                  { n_gpoly_srm.rsd_bot_thickness        0.0009    0.0009    0       }
  #                  { p_gpoly_srm.rsd_enclosure           -0.0035   -0.004    -0.004   }
  #                  { p_gpoly_srm.rsd_spacing              0.0114    0.0114    0.011   }
  #                  { p_gpoly_srm.rsd_bot_thickness        0.0003    0.0009    0       }
  #                }

  #---
  #  To define the config setting. Format: 
  #
  #      prop_name ,  ragne_start , range_end , scale_factor
  #
  set ga_config {

                  { 
                      ga_pool_size           4 
                      ga_mutation_ratio      0.1
                      ga_mutation_bits_ratio 0.5

                      ga_fit_script {
                          set qapath [$qaobj get_qapath]
                          set dir   [glob -type d -nocomplain -directory $qapath -tails *CORE*]
                          set qaItemReport [::QAItemReport #auto [$qaobj getName] $dir "${qapath}/$dir"]
                          set ccdist [$qaItemReport get_ccDist]
                          puts "ccdist: $ccdist"

                          set dir   [glob -type d -nocomplain -directory $qapath -tails *tcb*]
                          set qaItemReport [::QAItemReport #auto [$qaobj getName] $dir "${qapath}/$dir"]
                          set spdist [$qaItemReport get_spDist]
                          puts "spdist: $spdist"


                          #--- error handling
                          if { $ccdist == "NA" } {
                              set ccdist 1000000
                          }

                          #--- error handling
                          if { $spdist == "NA" } {
                              set spdist 1000000
                          }

                          #--- the big the stdev, the worse the score
                          return [expr 100/($ccdist + $spdist)]
                      }

                      ga_stop_script {
                          if { $_iteration > 2 } {
                              return 1
                          } else {
                              return 0
                          }
                      }
                  }

                  { n_gpoly_svt.rsd_enclosure            -0.010   0        10000  -0.005 }   
                  { n_gpoly_svt.rsd_spacing              0.008    0.012    10000  0.010  }
                  { n_gpoly_svt.rsd_bot_thickness        -0.010   0        10000  0      }
                  { p_gpoly_svt.rsd_enclosure            -0.010   0        10000  -0.005 }   
                  { p_gpoly_svt.rsd_spacing              0.008    0.012    10000  0.009  }
                  { p_gpoly_svt.rsd_bot_thickness        -0.010   0        10000  0      }
  }
  #--- end of ga_config

}




