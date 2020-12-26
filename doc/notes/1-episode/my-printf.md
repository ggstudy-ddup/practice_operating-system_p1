# My printf

## 1. Basic
#### 1.1 Video Mem.

*Starts from* ***0x68000***

From this address, what ever you write into the memory would be put on the
screen by the **graphics card**.

> Image 1.1.1
>
>   0x68000   text (ASCII)
>         |   |
> Low     V   V                High
> --+---+---+---+---+---+---+---+--
>   |   |   | H |   | e |   | l |  
>   |   |   |   |   |   |   |   |  
> --+---+---+---+---+---+---+---+--
>        ^ ^
>        | |
>       Color -- high byte and low byte

