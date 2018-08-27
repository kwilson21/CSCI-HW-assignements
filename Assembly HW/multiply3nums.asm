  ; Kazon Wilson
  ; An RSC program that multiplies 3 numbers together and displays the product.
  
  JMP start
  
  ; Variables

  var1: 2
  var2: 3
  var3: 4
  counter: 0
  product: 0

  start:                  ; The label 'start'. The jump statement earlier jumps here
     LDAC var1            ; Load var1 into Accumulator

     ; Take 2's compliment of var1 to get ready for a loop.
     NOT       
     INC
       
     STAC counter         ; Store var1 into counter 
     LDAC var2            ; Load the second variable into Accumulator
     MOVAC                ; Move the contents of Accumulator to R
     STAC product         ; Store var2 into product
     LDAC counter         ; Load counter into AC     
     
  loop1:
     ; This loop works by first decrementing the counter, then adding var1 to itself var2 - 1 times.
     ; var2 was stored in product earlier, then R (var1) is added to it. The sum of these numbers 
     ; are then stored into product and is done repeatedly until the counter (var2 - 1) reaches 0.
     ; For example, if var 1 and 2 both equal 8, then var2 is stored in product, and 8 and 8 get added together,
     ; the sum becomes the new product (16). In the next go around, 16 and 8 gets added
     ; and the process is repeated until the counter (var2 - 1) reaches 0 essentially doing (8 + 8) 7 times.

     INC                  ; Increment AC (counter - 1) 
     JMPZ done            ; Exit loop once counter = 0
     STAC counter         ; Store AC into counter
     LDAC product         ; Load second variable into AC 
     ADD                  ; Add Accumulator and R, move result into Accumulator 
     STAC product         ; Store the sum of AC and R into product
     LDAC counter         ; Load counter into AC
     JMP loop1            ; Jump back to the beginning of the loop
     
  done:
     LDAC var3            ; Load var3 into Accumulator

     ; Take 2's compliment of var3
     NOT       
     INC
       
     STAC counter         ; Store the 2's compliment of var3 into counter
     LDAC product         ; Load product into AC
     MOVAC                ; Move the contents of Accumulator to R
     LDAC counter         ; Load counter into AC

  loop2:
     INC                  ; Increment AC (counter - 1)
     JMPZ finish          ; Exit loop once counter = 0
     STAC counter         ; Store AC into counter
     LDAC product         ; Load product into AC
     ADD                  ; Add Accumulator and R, move result into Accumulator
     STAC product         ; Store the sum of AC and R into product
     LDAC counter         ; Load counter into AC
     JMP loop2            ; Jump back to the beginning of the loop

  finish:
     LDAC product         ; Load the final product into AC
     OUT                  ; Send Accumulator contents to Output Register   

      HALT                ; Stop execution
