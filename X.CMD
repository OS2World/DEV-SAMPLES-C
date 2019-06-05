mode com1:2400,e,7,1,idsr=off,odsr=off,octs=off,dtr=off,rts=off
set modem init=\nATL0E0\n
set dial prefix=ATM0DT
set dial suffix=;M1D\n
set hang up=\p+++\pATH\n
:go
if exist os2talk.obj call l2 os2talk
os2talk com1
pause
goto :go
