use std::error::Error;

use reqwest::header::{self};

#[tokio::main]
pub async fn main() -> Result<(), Box<dyn Error>> {
    let url = "https://adventofcode.com/2023/day/1/input";
    let client = reqwest::Client::new();
    let response = client.get(url).header(header::COOKIE,"session=53616c7465645f5fbc9383012aab356198665f7000c83ce40b59e48c45d5d4322520436e244c8a9bc44ccfdf6873e242f8111ac16ca625f532b317a8c3129255").send().await?;
    let lines: Vec<String> = response.text().await?.lines().map(String::from).collect();
    let mut ans = 0;
    for line in &lines {
        let first_int = line
            .chars()
            .find(|c| c.is_digit(10))
            .and_then(|c| c.to_digit(10));
        let last_int = line
            .chars()
            .rev()
            .find(|c| c.is_digit(10))
            .and_then(|c| c.to_digit(10));
        ans += match (first_int, last_int) {
            (Some(a), Some(b)) => a * 10 + b,
            _ => 0,
        };
    }
    println!("Result: {}", ans);
    Ok(())
}
