
int addBigMsg, CreateGxt, textt, Gxt

:ShowText    
    0DD0: CreateGxt = get_label_addr @textToGxt  
    0DD1: CreateGxt = get_func_addr_by_cstr_name CreateGxt 
     
    //0DD0: textt = get_label_addr @text ; a variavel textt deve receber o ponteiro para o texto.
    0DD0: Gxt = get_label_addr @gxt 
     
    0DD3: context_set_reg 0 value textt
    0DD3: context_set_reg 1 value Gxt
    0DD2: context_call_func CreateGxt
      
    
    0DD0: addBigMsg = get_label_addr @func // android
    0DD1: addBigMsg = get_func_addr_by_cstr_name addBigMsg // android 
    
    0DD3: context_set_reg 0 value Gxt // android 
    0DD3: context_set_reg 1 value 5000 // android 
    0DD3: context_set_reg 2 value 8 // android 
    0DD2: context_call_func AddBigMsg // android 
return
                    
:func 
hex
 "_ZN9CMessages13AddBigMessageEPtjt" 00
end

:textToGxt
hex 
 "_Z14AsciiToGxtCharPKcPt" 00
end 

:text
hex 
"~g~TESTANDOO" 00 
end

:gxt 
hex
00(32)
end