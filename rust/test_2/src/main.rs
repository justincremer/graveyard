fn main() {
    many_facs(30)
}

fn many_facs(n: u8) {
    for i in 1..n + 1 {
        println!("fac {} = {}", i, fac(i));
    }
}

fn fac(n: u8) -> u128 {
    match n {
        0 | 1 => 1,
        _ => (n as u128) * fac(n - 1),
    }
}
