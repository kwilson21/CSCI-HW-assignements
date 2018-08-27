  ; RSC Emulator Example
  
  JMP start
  
  ; Variables

  var1: 6
  var2: 0
  one: 1
  product: 0
  counter: 0

  start:       ; the label 'start'. The jump statement earlier jumps here
     LDAC one
     MOVAC
     
     LDAC var1
     STAC product
     SUB
     STAC var2
     
     ; Take 2's compliment of var1 and store it into counter
     NOT
     INC
     STAC counter

     
     
     LDAC product
     MOVAC

     LDAC counter

  loop1:
     INC
     JMPZ done
     STAC counter
     LDAC product
     ADD
     STAC product
     LDAC counter
     JMP loop1

  done:
     LDAC one
     MOVAC
     
     LDAC var2
     SUB
     STAC var2
     
     
     ; Take 2's compliment of var2 and store it into counter
     NOT
     INC
     STAC counter

     
     
     LDAC product
     MOVAC

     LDAC counter


   loop2:
     INC
     JMPZ done2
     STAC counter
     LDAC product
     ADD
     STAC product
     LDAC counter
     JMP loop2


  done2:
     LDAC one
     MOVAC
     LDAC var2
     SUB
     JMPZ finish
     JMP done

  finish:
     LDAC product
     OUT

      HALT      ; Stop execution
