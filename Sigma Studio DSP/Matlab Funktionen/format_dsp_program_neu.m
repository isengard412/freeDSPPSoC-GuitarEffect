string = fileread ('..\Insanity Basic Config\Basic_Config_INSANITY_IC 2\DMem0.dat');

i=1;
str newlines = "\n";
hexcode = [];
while i<length(string)
    if(STRCMP(string(i),newlines))
        hexcode = sprintf('%s0x%s, ',hexcode,string(i:i+1));
        i=i+2;
    else
        hexcode = sprintf('%s0x%s, ',hexcode,string(i:i+1));
        i=i+4;
    end
    
end
    
hexcode = hexcode(1:(length(hexcode)-2));
