using System;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows;
using System.Windows.Forms;

namespace Host_WPF
{
    public partial class MainWindow_WPF : Window
    {
        [DllImport("Guest_SfmlApp.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void RunApp(ref IntPtr handle);

        private readonly Guest_WinFormControl WinFormCanvas;

        public MainWindow_WPF()
        {
            InitializeComponent();

            // Host child control in code-behind so that XAML visualizer can render controls
            WinFormCanvas = new();
            WinFormHost.Child = new();
            WinFormHost.Child.Controls.Add(WinFormCanvas);
            WinFormCanvas.Dock = DockStyle.Fill;

            new Thread(() =>
            {
                RunApp(ref WinFormCanvas.HWND);
            }).Start();
        }
    }
}
