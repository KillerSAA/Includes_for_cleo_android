int pWidgets, iWidID

:SetWidgetPos
    Memory.GetLabelPointer(pWidgets, @_ZN15CTouchInterface10m_pWidgetsE)
    Memory.GetFuncPointerByCstrName(pWidgets, pWidgets)
    iWidID *= 0x4

    pWidgets += iWidID // sete o valor da variavel pWidID e das outras(de posição e escala) antes de chamar a função!                             
        
    Memory.Read(pWidgets, pWidgets, 4, False)
    pWidgets += 0xC   
    Memory.Write(pWidgets, fPosX, 4, False, True) // PosX
    pWidgets += 0x4
    Memory.Write(pWidgets, fPosY, 4, False, True) // PosY
    pWidgets += 0x4
    Memory.Write(pWidgets, fScaleX, 4, False, True) // scaleX
    pWidgets += 0x4
    Memory.Write(pWidgets, fScaleY, 4, False, True) // scaleY
return 


:_ZN15CTouchInterface10m_pWidgetsE
hex
    "_ZN15CTouchInterface10m_pWidgetsE" 00
end
