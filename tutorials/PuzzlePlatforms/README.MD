### Run Game with server ip
-game : Run with game mode  
-log  : With log
E:\svn\client\UnrealEngine\Engine\Binaries\Win64\UE4Editor.exe E:\github\ue4-examples\tutorials\PuzzlePlatforms\PuzzlePlatforms.uproject 127.0.0.1 -game -log

### Run Game With Map
E:\svn\client\UnrealEngine\Engine\Binaries\Win64\UE4Editor.exe E:\github\ue4-examples\tutorials\PuzzlePlatforms\PuzzlePlatforms.uproject /Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap 127.0.0.1 -game -log

### Run Server With Listen map
E:\svn\client\UnrealEngine\Engine\Binaries\Win64\UE4Editor.exe E:\github\ue4-examples\tutorials\PuzzlePlatforms\PuzzlePlatforms.uproject /Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen -server -log

### Generated Project bat
E:\svn\client\UnrealEngine\GenerateProjectFiles.bat -project="E:\github\ue4-examples\tutorials\PuzzlePlatforms\PuzzlePlatforms.uproject" -game -engine