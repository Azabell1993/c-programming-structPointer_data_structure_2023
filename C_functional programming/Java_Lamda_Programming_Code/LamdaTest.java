package Java_lambda_Programming_Code;
/*
    @ Developer : Azabell1993 Github master  
    @ Created   : 2023-03-07  
    @ fileName  : lambdaTest.java
    @ Purpose   : LambdaTest Success Code.
*/
import java.util.function.Function;

public class lambdaTest {
	private static int debug_hex = 0x00010000;
	
	public static void main(String[] args) {
		Function<h, Character> say_hello =(h) -> {
			
			if((debug_hex & debug_hex) != 0) {
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

// Build Method
// java .\lambdaTest.java     -- Window OS