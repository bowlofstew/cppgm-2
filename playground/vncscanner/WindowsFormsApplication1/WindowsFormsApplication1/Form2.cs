using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form2 : Form
    {
        public int cx1;
        public int cy1;
        public int cx2;
        public int cy2;
        public Bitmap cimg;
        private int cstate = 0;

        public Form2()
        {
            InitializeComponent();
            initCaptureWindow();
        }

        public void initCaptureWindow() {
            cx1 = -1;
            cy1 = -1;
            cx2 = -1;
            cy2 = -1;
        }

        public void setImage(Image img) {
            this.BackgroundImage = img;
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            this.TopMost = true;
            this.FormBorderStyle = FormBorderStyle.None;
            this.WindowState = FormWindowState.Maximized;
        }

        private void Form2_MouseClick(object sender, MouseEventArgs e)
        {
            if (cstate == 0)
            {
                cx1 = e.X;
                cy1 = e.Y;
                cstate = 1;
            }
            else // if (cstate == 1)
            {
                cx2 = e.X;
                cy2 = e.Y;
                Bitmap myImage = new Bitmap(cx2 - cx1, cy2 - cy1);
                Graphics g = Graphics.FromImage(myImage);
                g.CopyFromScreen(new Point(cx1, cy1), new Point(0, 0), new Size(cx2 - cx1, cy2 - cy1));
                myImage.Save("2.bmp");
                cimg = myImage;

                cstate = 0;
            }

            if (cstate == 0) {
                this.Hide();
            }
        }
    }
}
