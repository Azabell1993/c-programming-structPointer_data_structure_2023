/*
    @ Developer : Azabell1993 Github master  
    @ Created   : 2023-03-07  
    @ fileName  : lambdaTest.java
    @ Purpose   : LambdaTest Success Code.
*/
package Java_lambda_Programming_Code;

import java.util.function.Function;

public class lambdaTest_B {
    private static int debug_hex = 0x00010000;

    public static void main(String[] args) {
        Calculator calculator = new Calculator(10.0, 5.0);
        System.out.println(calculator(calculator, (h) -> h.a + h.b)); // 15.0
        System.out.println(calculator(calculator, (h) -> h.a - h.b)); // 5.0
        System.out.println(calculator(calculator, (h) -> h.a * h.b)); // 50.0
        System.out.println(calculator(calculator, (h) -> h.a / h.b)); // 2.0


        Calculator calculator2 = new Calculator(20.0, 100.0);
        System.out.println(calculator(calculator2, (h2222) -> h2222.a + h2222.b)); // 2.0
    }

    static class Calculator {
        double a, b;

        Calculator(double a, double b) {
            this.a = a;
            this.b = b;
        }
    }

    static double calculator(Calculator calculator, Function<Calculator, Double> func) {
        return func.apply(calculator);
    }
}