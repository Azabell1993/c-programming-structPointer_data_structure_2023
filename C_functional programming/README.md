## IDEA SKECTH  
  
These repository are i get idea motive at like Lamda what Java programming.  
  
## Lamda Programming aknowledges.  
> 1. Lamda is using functional programming what Anonymous functions in programming.  
> 2. Lamda concept like math aknowledge.  
> 3. Lamda is don't have name. this is only Anonymous functions. you cant don't input the a lot of parameter information can to be only one parameter at function of Lamda.    
> 4. What is the Lamda?   
    This is don't have name function. these Anonymous functions are have in common the characteristic of being first class citizens.  
  
## Advantages and disadvantages of LAMDA  
(1) Advantages   
```
    continue wirte the information at here space.  
```
(2) disadvantage  
```
    continue wirte the information at here space.  
```  
  
## Functional Programming Skecth  
There is a very subjective developer intention from @Azabell1993.  

=> get the result about "Hello World" message information

### 1. Basic original C code
```  
#include <stdio.h>
#include <stdlib.h>

#define debug_hex 0x00010000

typedef struct Hello {
    char (*sh)(struct Hello *h);
}h;

char say_hello(struct Hello *h) {
    if ((debug_hex & debug_hex) ? "true" : "false") {
        return (printf("Hello World!!\n"));
    } else {
        return (printf("Out of range memory values."));
    }
}

int main(int argc, char** argv) {
    h hello;
    hello.sh = &say_hello;
    hello.sh(&hello);

    return (0);
}
```    

### 2. JAVA Style Lamda Programming Code.  
```
package lamda_example_;
import java.util.function.Function;

public class LamdaTest {
	private static int debug_hex = 0x00010000;
	
	public static void main(String[] args) {
		Function<h, Character> say_hello =(h) -> {
			if((debug_hex & debug_hex) != 0 ) {
				System.out.println("Hello World!");
			} else {
				System.out.println("Out of range memeory values.");
			}
			return 1;
		};
        h hello = new h();
        hello.sh = say_hello;
        hello.sh.apply(hello);
	}
	
	static class h {
		Function<h, Character> sh;
	}
}
```  
  
> This code is so easy and don't have Functional characteristic. so you can make like this code.  
> but if you have alot of parameter, don't use like this code.  
> so I make this repository at information about functional programming.  
  
I want make functinal code at last year, but I don't have what I can make this skills. so I make C-code like LAMDA in this year.  
(but.....There is a very subjective developer intention from @Azabell1993.)  
  
Under method of Java Functional Programming.  
```
() -> {}
() -> 1
() -> { return 1; }

(int x) -> x+1
(x) -> x+1
x -> x+1
(int x) -> { return x+1; }
x -> { return x+1; }

(int x, int y) -> x+y
(x, y) -> x+y
(x, y) -> { return x+y; }

(String lam) -> lam.length()
lam -> lam.length()
(Thread lamT) -> { lamT.start(); }
lamT -> { lamT.start(); }
```  