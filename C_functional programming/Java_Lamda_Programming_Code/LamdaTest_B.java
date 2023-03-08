package Java_Lamda_Programming_Code;
/*
    @ Developer : Azabell1993 Github master  
    @ Created   : 2023-03-07  
    @ fileName  : LamdaTest.java
    @ Purpose   : LambdaTest Success Code.
*/
package Java_Lamda_Programming_Code;

import java.util.function.Function;

public class LamdaTest_B {
    private static int debug_hex = 0x00010000;

    public static void main(String[] args) {
        h calculator = new h(10.0, 5.0);
        System.out.println(calculate(calculator, (h) -> h.a + h.b)); // 15.0
        System.out.println(calculate(calculator, (h) -> h.a - h.b)); // 5.0
        System.out.println(calculate(calculator, (h) -> h.a * h.b)); // 50.0
        System.out.println(calculate(calculator, (h) -> h.a / h.b)); // 2.0
    }

    static class h {
        double a, b;

        h(double a, double b) {
            this.a = a;
            this.b = b;
        }
    }

    static double calculate(h calculator, Function<h, Double> f) {
        return f.apply(calculator);
    }
}