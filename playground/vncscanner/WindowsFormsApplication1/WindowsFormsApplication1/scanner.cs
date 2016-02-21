using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Runtime.InteropServices;
using System.IO;
using System.Threading;
using WindowsInput;


namespace WindowsFormsApplication1
{
    using Range = Tuple<int, int>;

    class ScannerUtil
    {
        public static Dictionary<char,int> hexMap = new Dictionary<char,int>() {
            { '0', 0 }, {'1', 1 }, {'2', 2}, {'3', 3 },
            { '4', 4 }, {'5', 5 }, {'6',6 }, {'7', 7 },
            { '8', 8 }, {'9', 9 }, {'a',10 }, {'b', 11 },
            { 'c', 12 }, {'d', 13 }, {'e', 14 }, {'f', 15 }
        };

        public static int noiseRangeThreshold = 5;
        public static int noiseColorThreshold = 40;


        public static int rgb2gray(Color x)
        {
            int ret = (x.R + x.G + x.B) / 3;

            if (ret < noiseColorThreshold)
                return 0;
            else
                return ret;
        }

        public static string dumpBitmap(ref Bitmap image1, Tuple<int, int> xrange, Tuple<int, int> yrange)
        {
            StringBuilder sb = new StringBuilder();
            for (int y = yrange.Item1; y < yrange.Item2; y++)
            {
                for (int x = xrange.Item1; x < xrange.Item2; x++)
                {
                    Color pixelColor = image1.GetPixel(x, y);
                    // int gray = rgb2gray(pixelColor);
                    int gray = (pixelColor.R + pixelColor.G + pixelColor.B) / 3;
                    sb.AppendFormat("{0,3} ", gray);
                }
                sb.AppendLine();
            }
            sb.AppendLine();
            return sb.ToString();
        }

        public static List<Range> image_segmentation_y(ref Bitmap image1)
        {
            int findState = 0; // 0, searching h0
                               // 1, searching h1
            int h0 = 0;
            int h1 = 0;

            List<Range> ypairs = new List<Range>();
            for (int y = 0; y < image1.Height; y++)
            {
                bool all0 = true;
                for (int x = 0; x < image1.Width; x++)
                {
                    int gray = rgb2gray(image1.GetPixel(x, y));
                    if (gray != 0)
                    {
                        all0 = false;
                        break;
                    }
                }
                if (all0 == false)
                {
                    if (findState == 0)
                    {
                        findState = 1;
                        h0 = y;
                    }
                }
                else
                {
                    if (findState == 1)
                    {
                        h1 = y;
                        findState = 0;
                        if ( (h1 - h0) > noiseRangeThreshold)
                        {
                            ypairs.Add(Tuple.Create(h0, h1));
                        }
                    }
                }
            }
            return ypairs;
        }

        public static List<Range> image_segmentation_x(ref Bitmap image1, int h0, int h1)
        {
            int findState = 0; // 0, searching h0
                               // 1, searching h1
            int w0 = 0;
            int w1 = 0;

            List<Tuple<int, int>> xpairs = new List<Tuple<int, int>>();
            for (int x = 0; x < image1.Width; x++)
            {
                bool all0 = true;
                for (int y = h0; y <= h1; y++)
                {
                    int gray = rgb2gray(image1.GetPixel(x, y));
                    if (gray != 0)
                    {
                        all0 = false;
                        break;
                    }
                }

                if (all0 == false)
                {
                    if (findState == 0)
                    {
                        findState = 1;
                        w0 = x;
                    }
                }
                else
                {
                    if (findState == 1)
                    {
                        w1 = x;
                        findState = 0;

                        if ((w1 - w0) > noiseRangeThreshold)
                        {
                            xpairs.Add(Tuple.Create(w0, w1));
                        }
                    }
                }
            }
            return xpairs;
        }

        public static CharBitmapProperty
           characterExtraction(ref Bitmap input, Range xrange, Range yrange)
        {
            int x0 = xrange.Item1;
            int x1 = xrange.Item2;
            int y0 = yrange.Item1;
            int y1 = yrange.Item2;

            // TODO: 'b', 'd' , 'f' are taller than normal number char
            //       If number digits are at the same line as 'b', 'd', 'f', 
            //       their bitmap would have one more line of bits. 
            //       Try to ignore this line by post processing the y0 line.
            while (true)
            {
                bool all0 = true;
                for (int i = x0; i < x1; i++)
                {
                    if (rgb2gray(input.GetPixel(i, y0)) != 0)
                    {
                        all0 = false;
                        break;
                    }
                }
                if (all0)
                {
                    y0 = y0 + 1;
                }
                else {
                    break;
                }
            }

            int xm = (x1 + x0) / 2;
            int ym = (y1 + y0) / 2;

            //
            //  00 01
            //  10 11
            //
            int score00 = 0;
            int score01 = 0;
            int score10 = 0;
            int score11 = 0;

            for (int x = x0; x < xm; x++)
            {
                for (int y = y0; y < ym; y++)
                {
                    score00 += rgb2gray(input.GetPixel(x, y));
                }
            }
            for (int x = xm; x < x1; x++)
            {
                for (int y = y0; y < ym; y++)
                {
                    score01 += rgb2gray(input.GetPixel(x, y));
                }
            }
            for (int x = x0; x < xm; x++)
            {
                for (int y = ym; y < y1; y++)
                {
                    score10 += rgb2gray(input.GetPixel(x, y));
                }
            }
            for (int x = xm; x < x1; x++)
            {
                for (int y = ym; y < y1; y++)
                {
                    score11 += rgb2gray(input.GetPixel(x, y));
                }
            }

            score00 = score00 / ((xm - x0) * (ym - y0));
            score01 = score01 / ((x1 - xm) * (ym - y0));
            score10 = score10 / ((xm - x0) * (y1 - ym));
            score11 = score11 / ((x1 - xm) * (y1 - ym));

            // debug
            // dumpBitmap(ref input, xrange, yrange);

            int total = score00 + score01 + score10 + score11;
            int[] tempA = { total, score00, score01, score10, score11 };

            CharBitmapProperty t = new CharBitmapProperty(tempA);
            // Console.WriteLine(t.ToString());

            return t;
        }

        public static Bitmap capturePartialScreen(Range xrange, Range yrange)
        {
            int x1 = xrange.Item1;
            int x2 = xrange.Item2;
            int y1 = yrange.Item1;
            int y2 = yrange.Item2;

            Bitmap myImage = new Bitmap(x2 - x1, y2 - y1);
            Graphics g = Graphics.FromImage(myImage);
            g.CopyFromScreen(new Point(x1, y1), new Point(0, 0), new Size(x2 - x1, y2 - y1));
            return myImage;
        }

        public static int hex2int(string hexcode)
        {
            int ret = 0;
            for (int i = 0; i < hexcode.Length; i++)
            {
                char c = hexcode[i];

                if (i == 0)
                {
                    ret = hexMap[c];
                }
                else {
                    ret = (ret << 4) + hexMap[c];
                }
            }
            return ret;
        }
    }


    class Scanner
    {
        private string mySavePath;
        private List<Tuple<CharBitmapProperty, char>> myDB;
        private IntPtr myWinHander;
        private Range myxRange;
        private Range myyRange;
        private int myTotalBytes;
        private int myLineNumBytes;
        private int myColNumBytes;
        private int myBytesRead;
        private int myLineNumRead;
        private List<string> myContent;
        private StreamWriter myLog;
        private StreamWriter myoutput;
        private int mySleepTime;


        private int mydbgLineIdx;
        private int mydbgCharIdx;
        private int mydbgPageIdx;
        private bool mydbg;
        

        public Scanner( IntPtr wHandler, Range xrange, Range yrange, string savePath)
        {
            myWinHander = wHandler;
            myxRange = xrange;
            myyRange = yrange;
            myTotalBytes = 0;
            myLineNumBytes = 0;
            myColNumBytes = 0;
            //----- scanning status ------//
            myBytesRead = 0;
            myLineNumRead = 0;
            myContent = new List<string>();
            myDB = new List<Tuple<CharBitmapProperty, char>>();
            mySavePath = savePath;
            myLog = new StreamWriter( mySavePath + @"\log.txt");
            myLog.AutoFlush = true;
            myoutput = new StreamWriter( mySavePath + @"\output.txt");
            myoutput.AutoFlush = true;
            mySleepTime = 2000;

            //----- for debuging
            mydbgLineIdx = 0;
            mydbgCharIdx = 0;
            mydbgPageIdx = 0;
            mydbg = false;
        }


        public int ScanDelay
        {
            get {
                return mySleepTime;
            }
            set {
                mySleepTime = value;
            }
        }

        public bool DebugEnable
        {
            get
            {
                return mydbg;
            }
            set
            {
                mydbg = value;
            }
        }

        public string LogFilePath
        {
            get
            {
                return mySavePath + @"\log.txt";
            }
        }

        public string outputFilePath
        {
            get
            {
                return mySavePath + @"\output.txt";
            }
        }


        [DllImport("USER32.DLL")]
        public static extern bool SetForegroundWindow(IntPtr hWnd);

        [DllImport("user32.dll")]
        private static extern int ShowWindow(IntPtr hWnd, uint Msg);

        public void foregroundTargetWindow(IntPtr w)
        {
            SetForegroundWindow(w);
            ShowWindow(w, 9);
        }


        public List<CharBitmapProperty> scanRow(ref Bitmap image, Range yrange)
        {
            List<CharBitmapProperty> retList = new List<CharBitmapProperty>();
            List<Range> xpairs = ScannerUtil.image_segmentation_x(ref image, yrange.Item1, yrange.Item2);
            foreach (var xrange in xpairs)
            {
                CharBitmapProperty t = ScannerUtil.characterExtraction(ref image, xrange, yrange);
                retList.Add(t);

                //dbg, dump one char
                // StringBuilder sb1 = new StringBuilder();
                // sb1.AppendFormat("char_{0}.txt", mydbgCharIdx++);
                // StreamWriter sw1 = new StreamWriter(sb1.ToString());
                // sw1.WriteLine(ScannerUtil.dumpBitmap(ref image, xrange, yrange));
                // sw1.Close();
            }

            //dbg, dump the whole line
            if (mydbg == true)
            {
                StringBuilder sb = new StringBuilder();
                sb.AppendFormat("line_{0}.txt", mydbgLineIdx++);
                StreamWriter sw = new StreamWriter(this.mySavePath + @"\" + sb.ToString());
                sw.WriteLine(ScannerUtil.dumpBitmap(ref image, Tuple.Create(0, image.Width), yrange));
                sw.Close();
            }
            return retList;
        }

        public void buildDB (ref Bitmap image1, Range yrange)
        {
            List<CharBitmapProperty> charDB = scanRow(ref image1, yrange);

            if (charDB.Count != 16)
            {
                throw new System.InvalidCastException("Build DB error! Should have 16 chars");
            }
            char[] chars = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
            for (int i = 0; i < charDB.Count; i++)
            {
                myDB.Add(Tuple.Create(charDB[i], chars[i]));
            }
            myoutput.Write(" ");
            for (int i = 0; i < chars.Length; i++)
            {
                myoutput.Write( chars[i]);
            }
            myoutput.WriteLine();
        }

        // TODO:
        public char charRecognition(CharBitmapProperty t)
        {
            char result = '?';
            int best_score = int.MaxValue;
            for (int i = 0; i < myDB.Count; i++)
            {
                CharBitmapProperty tmp = t - myDB[i].Item1;
                int theScore = tmp.magnitude();

                if (theScore < best_score)
                {
                    result = myDB[i].Item2;
                    best_score = theScore;
                }
            }
            return result;
        }

        public string lineRecognition(ref Bitmap image, Range yrange)
        {
            StringBuilder sb = new StringBuilder();
            List<CharBitmapProperty> charDB = scanRow(ref image, yrange);

            foreach (var charProp in charDB)
            {
                sb.Append(charRecognition( charProp) );
            }
            return sb.ToString();
        }

        public void buildHeader(ref Bitmap image1, Range yrange)
        {
            string headerStr = lineRecognition(ref image1, yrange);
            if (headerStr.Length != 24) {
                throw new System.InvalidCastException("Number of header line is wrong!");
            }
            myTotalBytes = ScannerUtil.hex2int( headerStr.Substring(0,8));
            myLineNumBytes = ScannerUtil.hex2int(headerStr.Substring(8, 8));
            myColNumBytes = ScannerUtil.hex2int(headerStr.Substring(16, 8));

            // debug
            myLog.WriteLine("Header -- Total Bytes: {0}", myTotalBytes);
            myLog.WriteLine("Header -- Line number bytes: {0}", myLineNumBytes);
            myLog.WriteLine("Header -- column number bytes: {0}", myColNumBytes);

            myoutput.WriteLine(" {0} {1} {2}", headerStr.Substring(0, 8), headerStr.Substring(8, 8), headerStr.Substring(16, 8));
        }

        public bool isFinished()
        {
            if (myBytesRead == myTotalBytes)
                return true;
            else
                return false;
        }

        public void nextPage()
        {
            InputSimulator.SimulateKeyPress(VirtualKeyCode.SPACE);
            Thread.Sleep(this.mySleepTime);
        }

        public void scanPage()
        {
            // 1. get image
            // 2. line detection
            // 3. build DB by first line
            // 4. OCR 2nd line (header)
            // 5. ORC the rest

            foregroundTargetWindow(this.myWinHander);
            if (myDB.Count == 0)  // first page
            {
                Thread.Sleep(this.mySleepTime);
            }
            Bitmap image = ScannerUtil.capturePartialScreen(myxRange, myyRange);
            List<Range> yranges = ScannerUtil.image_segmentation_y(ref image);

            if (mydbg)
            {
                StringBuilder pageNameSb = new StringBuilder();
                pageNameSb.AppendFormat("page_{0}.bmp", mydbgPageIdx);
                image.Save( this.mySavePath + @"\" + pageNameSb.ToString());
            }

            if (myDB.Count == 0)  // first page
            {
                if (yranges.Count < 2)
                {
                    throw new System.InvalidCastException("Bad header, less than two lines");
                }
                buildDB(ref image, yranges[0]);
                buildHeader(ref image, yranges[1]);
                yranges.RemoveRange(0,2);
            }

            //1. read line
            //2. if fail before all line is finished. wait a few seconds, continue
            //3. if success, hold the line content to a list
            //4. if all lines of the are done successfully, 
            //   update global variables and write the saved line to output file

            bool scanDone = false;
            List<string> scannedLines = new List<string>();
            int backup_myLineNumRead = myLineNumRead;
            int backup_myBytesRead = myBytesRead;
            int repeatCount = 0;

            do
            {
                try
                {
                    for (int i = 0; i < yranges.Count; i++)
                    {
                        string lineStr = lineRecognition(ref image, yranges[i]);
                        string lineNumStr = lineStr.Substring(0, myLineNumBytes * 2);
                        string contentStr = lineStr.Substring(myLineNumBytes * 2);
                        string checkSumStr = contentStr.Substring( contentStr.Length - 2);
                        contentStr = contentStr.Substring(0, contentStr.Length - 2);

                        int lineNum = ScannerUtil.hex2int(lineNumStr);
                        int checkSum = ScannerUtil.hex2int(checkSumStr);

                        StringBuilder sb = new StringBuilder();
                        sb.AppendFormat("{0} {1} {2}", lineNumStr, contentStr, checkSumStr);
                        myLog.WriteLine(sb.ToString());

                        // error checking line number
                        if (lineNum < myLineNumRead + 1)
                        {
                            // break;  // error, try scan the page again
                            myLog.WriteLine("Bad line number exception {0} != {1}", lineNum, myLineNumRead+1);
                            throw new System.InvalidCastException("Bad Line number!");
                        }
                        else if (lineNum > myLineNumRead + 1)
                        {
                            // error, something missing, no way to recover
                            myLog.WriteLine("Bad line number exception {0} != {1}", lineNum, myLineNumRead + 1);
                            throw new System.InvalidCastException("Bad content size");
                        }
                        else  // line number is good, check contents
                        {
                         
                            // content check sum
                            //
                            int localCheckSum = 0;
                            for (int k = 0; k < contentStr.Length; k++)
                            {
                                string tmp = contentStr.Substring(k,1);
                                localCheckSum += ScannerUtil.hex2int(tmp);
                            }
                            if (localCheckSum % 256 != checkSum)
                            {
                                myLog.WriteLine("Bad content checksum : line {0} expect {1} got {2}", lineNum, checkSum, localCheckSum);
                                throw new System.InvalidCastException("Bad content size");
                            }

                            // line number matching
                            //
                            myLineNumRead = lineNum;
                            if (contentStr.Length > myColNumBytes * 2)
                            {
                                myLog.WriteLine("Bad content size #1 : line {0} expect {1} got {2}",lineNum, myColNumBytes, contentStr.Length * 2);
                                myLog.WriteLine(contentStr);
                                throw new System.InvalidCastException("Bad content size");
                            }
                            else if (contentStr.Length < myColNumBytes * 2)
                            {
                                if ((myBytesRead + contentStr.Length / 2) == myTotalBytes)
                                {
                                    // normal ending
                                    scannedLines.Add(sb.ToString());
                                    myBytesRead += contentStr.Length / 2;
                                    myLog.WriteLine("Reach the last byte of file");
                                }
                                else
                                {
                                    myLog.WriteLine("Bad content size #2: line {0} expect {1} got {2}", lineNum, myColNumBytes, contentStr.Length * 2);
                                    myLog.WriteLine(contentStr);
                                    throw new System.InvalidCastException("Bad content size: line {0}");
                                }
                            }
                            else
                            {
                                // normal;
                                myLog.WriteLine("Byets read so far: {0}",myBytesRead);
                                scannedLines.Add(sb.ToString());
                                myBytesRead += contentStr.Length / 2;
                                myLog.WriteLine("Successfully parsed line {0}", lineNumStr);
                                myLog.WriteLine("Total bytes : {0}  Bytes read : {1}", myTotalBytes, myBytesRead);
                            }
                        }
                    } // end of for loop
                } // try block
                catch (Exception ex)
                {
                    scanDone = false;
                    myBytesRead = backup_myBytesRead;
                    myLineNumRead = backup_myLineNumRead;
                    scannedLines.Clear();
                    Thread.Sleep(mySleepTime);

                    foregroundTargetWindow(myWinHander);
                    image = ScannerUtil.capturePartialScreen(myxRange, myyRange);
                    yranges = ScannerUtil.image_segmentation_y(ref image);

                    myLog.WriteLine("Recan page {0} repeat count {1}", mydbgPageIdx, repeatCount);
                    if (mydbg)
                    {
                        StringBuilder pageNameSb2 = new StringBuilder();
                        pageNameSb2.AppendFormat("page_{0}_{1}.bmp", mydbgPageIdx, repeatCount++);
                        image.Save(this.mySavePath + @"\" +  pageNameSb2.ToString());
                    }
                    
                    continue;
                }

                scanDone = true;
                foreach (var str in scannedLines)
                {
                    myoutput.Write(" ");
                    myoutput.WriteLine(str);
                }
                if (myBytesRead == myTotalBytes)
                {
                    myoutput.Close();
                }
                break;
            }
            while (scanDone == false);
            mydbgPageIdx++;
        }
    }
}
