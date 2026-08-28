# ft_push_swap

A sorting algorithm project from 42: sort a stack of integers using only two stacks and a limited set of operations (`push`, `swap`, `rotate`, `reverse rotate`), printing the minimal sequence of moves needed.

## Technical overview

- C, uses a radix sort for larger stacks (>5 elements) and a simpler insertion-based approach for small ones, to keep the number of operations low
- Input is validated for duplicates, non-numeric values, and integer overflow before sorting starts

## Compile & run

```bash
git clone https://github.com/regalfelix/ft_push_swap.git
cd ft_push_swap
make
./push_swap 4 67 3 87 23 85 42
```

The list of operations is printed to stdout, one per line (`pa`, `pb`, `sa`, `sb`, `ra`, `rb`, `rr`, `rra`, etc.).

## License

This project is licensed under the [MIT LICENSE](LICENSE)
