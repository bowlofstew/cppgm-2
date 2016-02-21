using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.Runtime.InteropServices;
using WindowsInput;
using System.Threading;
using System.IO;
using System.Security.Permissions;
using System.Security;
using System.Deployment.Application;
using System.Xml;



namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private Form2 form2 = null;
        private int cx1 = -1;
        private int cy1 = -1;
        private int cx2 = -1;
        private int cy2 = -1;
        private List<Tuple<CharBitmapProperty, char>> myDB;
        private Scanner myScanner;
        private XmlDocument myConfig;
        private string myConfigName;
        private string mySavePath;


        public Form1()
        {
            InitializeComponent();

            //--- initialize GUI
            this.button1.Enabled = false;
            this.button6.Enabled = false;
            this.checkBox1.Enabled = false;
            this.myScanner = null;

            this.myConfig = new XmlDocument();
            this.myConfigName = "vncscanner.xml";
                
            this.initialize_config();
        }

        public void initialize_config()
        {
            mySavePath = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + @"\VncScanner";

            if (!Directory.Exists( mySavePath)) {
                Directory.CreateDirectory( mySavePath );
            }

            
            string fullPath = mySavePath + @"\" + myConfigName;
            Console.WriteLine(fullPath);

            if (File.Exists(fullPath))
            {
                myConfig.Load(fullPath);
            }
            else
            {
                XmlElement root = myConfig.CreateElement("settings");
                myConfig.AppendChild(root);

                XmlElement winTitles = myConfig.CreateElement("winTitles");
                XmlElement win3 = myConfig.CreateElement("window");
                win3.SetAttribute("title", "roll:1 (rhuang) - TightVNC Viewer");
                winTitles.AppendChild(win3);

                XmlElement delay = myConfig.CreateElement("delay");
                delay.SetAttribute("delay", "2000");
                XmlElement debug = myConfig.CreateElement("debug");
                debug.SetAttribute("debug", "0");

                root.AppendChild(winTitles);
                root.AppendChild(delay);
                root.AppendChild(debug);

                myConfig.Save(fullPath);
            }

            //--- show the xml setting on GUI
            //
            XmlElement elem = (XmlElement)myConfig.SelectSingleNode("settings/winTitles");
            foreach (XmlElement subItem in elem.ChildNodes)
            {
                this.comboBox1.Items.Add( subItem.GetAttribute("title") );
            }
            XmlElement elem2 = (XmlElement)myConfig.SelectSingleNode("settings/delay");
            this.textBox1.Text = elem2.GetAttribute("delay");
            XmlElement elem3 = (XmlElement)myConfig.SelectSingleNode("settings/debug");
            int debugInput = int.Parse(elem3.GetAttribute("debug"));
            if (debugInput > 0) {
                this.checkBox1.Checked = true;
            }
        }

        private void captureScreen() {
            Bitmap myImage = new Bitmap(1920, 1080);
            Graphics g = Graphics.FromImage(myImage);
            g.CopyFromScreen(new Point(0, 0), new Point(0, 0), new Size(1920, 1080));
            this.pictureBox1.Image = myImage;
        }

        private void refreshGUI()
        {
            IntPtr winHandler = getTargetWindow();
            if (winHandler == IntPtr.Zero)
            {
                this.button1.Enabled = false;
                this.button6.Enabled = false;
                this.checkBox1.Enabled = false;
            }
            else
            {
                this.button1.Enabled = true;
                this.button6.Enabled = true;
                this.checkBox1.Enabled = true;
            }
        }

        private void captureRegion_Click(object sender, EventArgs e)
        {
            foregroundTargetWindow( getTargetWindow() );
            this.captureScreen();

            if (form2 == null)
            {
                form2 = new Form2();
            }           
            form2.setImage( this.pictureBox1.Image);
            form2.ShowDialog();

            cx1 = form2.cx1;
            cy1 = form2.cy1;

            cx2 = form2.cx2;
            cy2 = form2.cy2;

            Console.WriteLine("form2 is now closed {0} {1} {2} {3}", cx1, cy1, cx2, cy2);
            this.pictureBox1.Image = form2.cimg;
            this.pictureBox1.Image.Save("partial.bmp");
            foregroundTargetWindow( this.Handle );
        }

        
        [DllImport("USER32.DLL", CharSet = CharSet.Unicode)]
        public static extern IntPtr FindWindow(string lpClassName, string lpWindowName);

        [DllImport("USER32.DLL")]
        public static extern bool SetForegroundWindow(IntPtr hWnd);

        [DllImport("user32.dll")]
        private static extern int ShowWindow(IntPtr hWnd, uint Msg);

        private IntPtr getTargetWindow()
        {
            IntPtr winhandler = IntPtr.Zero;
            string winString = this.comboBox1.Text;

            if (winString == "") {
                return IntPtr.Zero;
            }
            winhandler = FindWindow(null, winString);
            return winhandler;
        }

        private void foregroundTargetWindow(IntPtr w)
        {
            SetForegroundWindow(w);
            ShowWindow(w, 9);
        }

        private void test_keystroke(string target)
        {
            foregroundTargetWindow( getTargetWindow() );
            //InputSimulator.SimulateKeyPress(VirtualKeyCode.VK_H);
            //InputSimulator.SimulateKeyPress(VirtualKeyCode.VK_E);
            //InputSimulator.SimulateKeyPress(VirtualKeyCode.VK_L);
            //InputSimulator.SimulateKeyPress(VirtualKeyCode.VK_L);
            //InputSimulator.SimulateKeyPress(VirtualKeyCode.VK_O);
            //InputSimulator.SimulateKeyPress(VirtualKeyCode.VK_1);
            //InputSimulator.SimulateKeyPress(VirtualKeyCode.RETURN);
            InputSimulator.SimulateKeyPress(VirtualKeyCode.SPACE);
            Thread.Sleep(500);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.comboBox1.Enabled = false;
            this.textBox1.Enabled = false;
            this.checkBox1.Enabled = false;
            this.button1.Enabled = false;
            this.button6.Enabled = false;

            myScanner = new Scanner(getTargetWindow(), Tuple.Create(cx1, cx2), Tuple.Create(cy1, cy2), mySavePath);
            myScanner.DebugEnable = this.checkBox1.Checked;
            int scanDelay = Int32.Parse(this.textBox1.Text);
            if (scanDelay < 1000)
            {
                scanDelay = 1000;
            }
            myScanner.ScanDelay = scanDelay;

            backgroundWorker1.RunWorkerAsync();
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            while (true)
            {
                myScanner.scanPage();

                if (myScanner.isFinished())
                {
                    break;
                }
                else
                {
                    myScanner.nextPage();
                }
            }
        }

        private void backgroundWorker1_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            SetForegroundWindow(this.Handle);
            SaveFileDialog dialog = new SaveFileDialog();
            dialog.Title = "Save output file";
            dialog.ShowDialog();

            if (dialog.FileName != "")
            {
                System.IO.FileStream fs = (System.IO.FileStream)dialog.OpenFile();
                StreamWriter sw = new StreamWriter(fs);
                using ( StreamReader sr = new StreamReader(myScanner.outputFilePath)) {
                    string line;
                    while ( (line = sr.ReadLine()) != null) {
                        sw.WriteLine( line );
                    }
                    sr.Close();
                }
                sw.Close();
            }

            Process.Start(mySavePath);
            Console.WriteLine("Work complete!");
        }

        private void comboBox1_SelectionChangeCommitted(object sender, EventArgs e)
        {
            refreshGUI();
        }

        private void comboBox1_TextChanged(object sender, EventArgs e)
        {
            refreshGUI();
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            // save the current GUI setting to myConfig

            XmlElement elem = (XmlElement)myConfig.SelectSingleNode("settings/winTitles");
            string currentTitle = this.comboBox1.Text;

            if (currentTitle != "")
            {
                bool foundTitle = false;
                foreach (XmlElement subItem in elem.ChildNodes)
                {
                    if (currentTitle == subItem.GetAttribute("title"))
                    {
                        foundTitle = true;
                        break;
                    }
                }
                if (foundTitle == false)
                {
                    XmlElement a = myConfig.CreateElement("window");
                    a.SetAttribute("title", currentTitle);
                    elem.AppendChild(a);
                }
            }

            XmlElement elem2 = (XmlElement)myConfig.SelectSingleNode("settings/delay");
            elem2.SetAttribute("delay", this.textBox1.Text);

            XmlElement elem3 = (XmlElement)myConfig.SelectSingleNode("settings/debug");
            if (this.checkBox1.Checked)
            {
                elem3.SetAttribute("debug","1");
            }

            string fullPath = this.mySavePath + @"\" + myConfigName;
            myConfig.Save(fullPath);
        }
    }
}


