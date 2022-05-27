using System;
using System.Windows.Forms;

namespace Host_WPF
{
    public partial class Guest_WinFormControl : UserControl
    {
        public ref IntPtr HWND { get { return ref _handle; } }
        private IntPtr _handle;

        public Guest_WinFormControl()
        {
            InitializeComponent();

            _handle = Handle;
        }

        protected override void OnHandleDestroyed(EventArgs e)
        {
            base.OnHandleDestroyed(e);
            // "close" handle to simulate native close event
            _handle = IntPtr.Zero;
        }
    }
}
