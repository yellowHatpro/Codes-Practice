use std::error::Error;

#[tokio::main]
pub async fn main() -> Result<(), Box<dyn Error>> {
    let file = tokio::fs::read_to_string("./src/input2.txt").await?;
    let lines: Vec<String> = file.lines().map(String::from).collect();
    let mut ans = 0;
    for (i, line) in lines.iter().enumerate() {
        let mut bool = true;
        //remove everything before a colon
        let mut split = line.split(":");
        split.next();
        let line = split.next().unwrap().to_string();
        //remove everything after a space
        let mut split = line.split(";");
        for color in split {
            //segregate the color and the number and store it in a tuple
            let mut color_split = color.split(",");
            for color_pair in color_split{
                let mut iter = color_pair.split_whitespace();
                if let (num_iter, color_iter) = (iter.next().unwrap(), iter.next().unwrap()) {
                    match color_iter {
                        "red" => {
                            if num_iter.parse::<i32>().unwrap() > 12 {
                                bool = false;
                                break
                            }
                        }
                        "green" => {
                            if num_iter.parse::<i32>().unwrap() > 13 {
                                bool = false;
                                break
                            }
                        }
                        "blue" => {
                            if num_iter.parse::<i32>().unwrap() > 14 {
                                bool = false;
                                break
                            }
                        }
                        _ => ()
                    }

                }
            }
        }
        if bool{
            ans+=i+1;
        }
    }
    println!("Result: {}", ans);
    Ok(())
}