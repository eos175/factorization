# Decompose a number into 2 prime co-factors

One of the requirements for [Telegram Authentication](https://core.telegram.org/mtproto/samples-auth_key#3-pq-17ed48941a08f981-decomposed-into-2-prime-cofactors) is decomposing a given number into 2 prime co-factors. In particular `P * Q = N, where N < 2 ^ 63`


## Install

```bash

sudo apt install python3-venv python3-dev

python3 -m venv .venv
. .venv/bin/activate
pip install git+https://github.com/eos175/factorization.git

```

## Usage

### Python

```python

>>> from factorization import factorize


>>> factorize(1450412926811329079)
(1145059067, 1266670837)


```

### c++

```c++

int128_t pq;
int128_t p, q;

pq = 3102221862710776733U;

p = BrentRichard(pq);
q = pq / p;


```


## Reference

https://stackoverflow.com/questions/31953836/decompose-a-number-into-2-prime-co-factors

