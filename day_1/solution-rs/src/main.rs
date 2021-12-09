use std::fs::File;
use std::io::{prelude::*, BufReader};

fn read_file (file_name: &str) -> Result<i32, std::io::Error> {
    let file = File::open(&file_name)?;
    let reader = BufReader::new(file);

    let mut prev = -1;
    let mut total = 0;
    for line in reader.lines() {
        let curr: i32;

        if (line.as_ref().unwrap()).is_empty() { break; }

        curr = line.unwrap().parse().unwrap();
        if prev != -1 {
            if prev < curr { total += 1; }
        }
        
        prev = curr;
    }
    Ok(total)
}

fn main() {
    let input_file = "../input";
    let result = read_file(input_file);
    println!("{}", result.unwrap());
}
