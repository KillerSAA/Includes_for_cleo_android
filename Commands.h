:GetPlayerWeaponMode
    int iIb, pPlayerWeaponMode = 0x951FA8 // CCamera

    pPlayerWeaponMode += 0x7B4 // PlayerWeaponMode
    get_image_base iIb 
    pPlayerWeaponMode += iIb 
return
// 0x35(53): mirando com fuzis,smgs, etc...
// 0x7: mirando com a sniper

:GetPlayerPed
    int pPed, pGetPed

    0DD0: pGetPed = get_label_addr @_ZN6CPools6GetPedEi // android 
    0DD1: pGetPed = get_func_addr_by_cstr_name pGetPed // android 

    0DD3: context_set_reg 0 value $PLAYER_ACTOR 
    context_call_func pGetPed
    0DD4: pPed = context_get_reg 0
return

:GetActiveCameraStruct // Ccam struct 
    int pTheCamera = 0x951FA8/*Ccamera struct*/, iActiveCam, offset

    pTheCamera += 0x57 // ActiveCam
    Memory.Read(iActiveCam, pTheCamera, 1, true)

    switch iActiveCam  
        case 0 
            offset = 0x170
        case 1 
            offset = 0x2E0
        case 2 
            offset = 0x450
    endswitch  
    pTheCamera = 0x951FA8
    pTheCamera += offset   
return   

:_ZN6CPools6GetPedEi
hex
    "_ZN6CPools6GetPedEi" 00
end

