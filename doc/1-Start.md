# UE4 新手问题
## 如果找到程序入口函数 Main
Visual Studio 使用 F10 启动编辑器或游戏，程序会暂停到 WinMain 函数起始处   

## ::IsDebuggerPresent() 函数
IsDebuggerPresent是确定调用进程是否由用户模式的调试器调试。   
BOOL WINAPI IsDebuggerPresent(void);   

[Microsoft](https://msdn.microsoft.com/en-us/library/windows/desktop/ms680345(v=vs.85).aspx)  

## 以游戏模式启动，方便使用NSight 进行Debug  
属性命令行参数中添加 "-game"
