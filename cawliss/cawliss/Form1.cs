using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace cawliss
{
    public partial class Form1 : Form
    {
        public SerialPort myport;


        public Form1()
        {
            InitializeComponent();
            init();
        }

        private void start_btn_Click(object sender, EventArgs e)
        {
            myport.WriteLine("O");

            start_btn.Enabled = false;
            Stop_btn.Enabled = true;
        }

        private void Stop_btn_Click(object sender, EventArgs e)
        {
            myport.WriteLine("F");

            start_btn.Enabled = true;
            Stop_btn.Enabled = false;
        }
        
        
        private void init()
        {
            try
            {
                myport = new SerialPort();
                myport.BaudRate = 9600;
                myport.PortName = "COM3";
                myport.Open();
            }
               
            catch (Exception)
            {
                MessageBox.Show("Euhh march pas");
              
            }
            start_btn.Enabled = true;
            Stop_btn.Enabled = false;
        }
    }
}
