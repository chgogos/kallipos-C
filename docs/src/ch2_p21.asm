.LC1:
    .string "The square root of %.2f is %.8f\n"      

main:
    push    rbp                              
    mov     rbp, rsp                         
    sub     rsp, 16                           

    movsd   xmm0, QWORD PTR .LC0[rip]         
    movsd   QWORD PTR [rbp-8], xmm0           

    mov     rax, QWORD PTR [rbp-8]            
    movq    xmm0, rax                        
    call    sqrt                             

    movq    rax, xmm0                        
    mov     QWORD PTR [rbp-16], rax           

    movsd   xmm0, QWORD PTR [rbp-16]          
    mov     rax, QWORD PTR [rbp-8]            
    movapd  xmm1, xmm0                       
    movq    xmm0, rax                        

    mov     edi, OFFSET FLAT:.LC1             
    mov     eax, 2                            
    call    printf                           

    mov     eax, 0                            
    leave                                     
    ret                                       

.LC0:
    .long 0                                  
    .long 1073741824                         
