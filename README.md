# collatz-calc
Calculates Collatz conjecure or Hailstone sequence for given natural number (64-bit).

```
Usage: ./collatz [ b1101 | 007 | 1234 | 0xffff ]
```

## Expected output

Just input the starting number as first and only application argument:

```
./collatz 276592
```

As result, the entire sequence starting from n is printed until it encounters the repetitive loop at 1.

<img width="630" height="273" alt="Decimal output for 276952" src="https://github.com/user-attachments/assets/76a22250-826e-4fc5-ae1e-5c9e177901b4" />

### Alternative binary output

When giving the number (n = 7775) as binary format each number in a sequence is printed as binary and decimal on its own line.

```
./collatz b1111001011111
```

And the result will look like this:

<img width="415" height="901" alt="Binary output for 7775" src="https://github.com/user-attachments/assets/542791ee-e8ef-4d95-83b3-7a4fb632c24c" />

