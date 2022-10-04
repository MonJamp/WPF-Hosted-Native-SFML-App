This project is a proof of concept on how to host a native graphics application within a managed WPF application.
This project shows how to retrieve the native window handle from a WPF control and pass it to a C++ program. The C++ program is able to use the window handle to draw graphics.

The C++ program is compiled as a library with an exposed function which accepts a WinApi window handle as a parameter.
In order to retrieve the native window handle from WPF, a WinForms host control is used. Using a WinForms control, it is made easier to retrieve the window handle.
The window handle is retrieved from the WinForms control to the WPF application; then it is sent to the C++ library where it can be consumed by the SFML library to create a rendering target.
In this example, the C++ library is hosted on its own thread which is managed by the .NET Core framework.

This approach would be useful in situations where a high performance graphics application is needed in conjuction with a flexible desktop GUI framework such as WPF/UWP/WinUI/MAUI.
