rmdir bin /s /q
rmdir test\bin /s /q
mkdir bin
mkdir test\bin
set PATH=%PATH%;H:\Documents\bin;C:\Program Files (x86)\GnuWin32\bin; H:\Documents\lib\gcc\x86_64-pc-cygwin\6.4.0

make

