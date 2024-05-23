use std::io;
use std::process::id;

fn main() {
    let mut x = 5;
    println!("The value of x is: {x}");
    x = 6;
    println!("The value of x is: {x}");

    // addition
    let sum = 5 + 10;

    // subtraction
    let difference = 95.5 - 4.3;

    // multiplication
    let product = 4 * 30;

    // division
    let quotient = 56.7 / 32.2;
    let truncated = 5 / 3; // Results in -1
    println!("truncated: {truncated}");

    // remainder
    let remainder = 43 % 5;
    let f:bool = false;
    let c:char = 'z';
    let tup: (i32, f64, u8) = (500, 1.1, 3);
    let (x, y, z) = tup;
    println!("{x}");
    let t = tup.0;
    println!("{t}");
    let arr: [i32; 5] = [1,2,3,4,5];
    let a = [3;5];
    let b = arr[2];
    let mut idx = String:: new();
    io::stdin().read_line(&mut idx).expect("faild to readline");
    let idx: usize = idx.trim().parse().expect("please enter a number");
    let element = arr[idx];
    println!("element is {element}");


}
