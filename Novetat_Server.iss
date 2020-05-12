; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Novetat_server"
#define MyAppVersion "1.0"
#define MyAppPublisher "Bubi Gaudrioles"
#define MyAppURL "https://github.com/Gaudrioles"
#define MyAppExeName "Novetat_server.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{9AFEFED3-6B04-4521-92CC-B5ED49F49869}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={commonpf64}\{#MyAppName}
DisableProgramGroupPage=yes
LicenseFile=
; Uncomment the following line to run in non administrative install mode (install for current user only.)
;PrivilegesRequired=lowest
OutputDir=D:\Output
OutputBaseFilename=Novetat_server_Setup
SetupIconFile=D:\CodeBlocksProjets\novetat_server\icons\icon.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "french"; MessagesFile: "compiler:Languages\French.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Dirs]
Name: "{app}"; Permissions: users-full

[Files]
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\Novetat_server.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\share\*"; DestDir: "{app}\share"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\lib\*"; DestDir: "{app}\lib"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\CodeBlocksProjets\novetat_server\icons\*"; DestDir: "{app}\icons"; Flags: ignoreversion recursesubdirs createallsubdirs

Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libatk-1.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libbz2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libcairo-2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libcairo-gobject-2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libcrypto-1_1-x64.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libdatrie-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libepoxy-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libexpat-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libffi-7.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libfontconfig-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libfreetype-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libfribidi-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libgcc_s_seh-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libgdk-3-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libgdk_pixbuf-2.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libgio-2.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libglib-2.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libgmodule-2.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libgobject-2.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libgraphite2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libgtk-3-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libharfbuzz-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libiconv-2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libintl-8.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libpango-1.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libpangocairo-1.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libpangoft2-1.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libpangowin32-1.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libpcre-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libpixman-1-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libpng16-16.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libsqlite3-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libthai-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\CodeBlocksProjets\novetat_server\bin\Release\zlib1.dll"; DestDir: "{app}"; Flags: ignoreversion

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

