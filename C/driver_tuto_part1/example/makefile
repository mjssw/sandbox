TARGET = example
TARGETDIR = ..\..\..\..\bin

ASM = ml
CPP = cl
RSC = rc.exe
F90 = df.exe
MTL = midl.exe
REBASE = rebase.exe

OBJDIR = .\obj\i386

ASM_PROJ=/coff /c /Fo$(OBJDIR)\\



CPP_PROJ=/nologo /MD /W3 /Oxs /Gz /Zi \
	/I "..\..\..\..\inc" \
	/I "\NTDDK\inc" \
        /D "WIN32" /D "_WINDOWS" \
	/Fr$(OBJDIR)\\ /Fo$(OBJDIR)\\ /Fd$(OBJDIR)\\ /c

LIB32= link.exe 
LIB32_FLAGS = /LIBPATH:..\..\..\..\lib /LIBPATH:\NTDDK\libfre\i386 /DEBUG /PDB:$(TARGETDIR)\SYMBOLS\$(TARGET).PDB  -entry:DriverEntry  /SUBSYSTEM:NATIVE /nologo $(LIBS) /out:$(TARGETDIR)\$(TARGET).sys



OBJS   = \
	$(OBJDIR)\entry.obj \
	$(OBJDIR)\functions.obj

LIBS = \
       wdm.lib \
       ntoskrnl.lib
 
# This is a comment
$(TARGETDIR)\$(TARGET): $(OBJDIR) $(TARGETDIR) $(OBJS) $(RESFILE)
    $(LIB32) $(LIB32_FLAGS) $(OBJS) $(LIBS) $(RESFILE)
    $(REBASE) -b 0x00400000 -x $(TARGETDIR)\SYMBOLS -a $(TARGETDIR)\$(TARGET)

{.\}.c{$(OBJDIR)}.obj::
	$(CPP) $(CPP_PROJ) $<

{.\}.cpp{$(OBJDIR)}.obj::
	$(CPP) $(CPP_PROJ) $<


{.\}.asm{$(OBJDIR)}.obj::
	$(ASM) $(ASM_PROJ) $<


{.\}.rc{$(OBJDIR)}.res::
	$(RSC) $(RES_PROJ) $<

$(OBJDIR):
    if not exist "$(OBJDIR)/$(NULL)" mkdir "$(OBJDIR)"

$(TARGETDIR):
    if not exist "$(TARGETDIR)/$(NULL)" mkdir "$(TARGETDIR)"


CLEAN:
	-@erase /S /Q $(OBJDIR)
