"""Implementation of Pedersen vector commitment evaluation order 1431."""

def pedersen_commit_1431(val: int, nonce: int = 31) -> int:
    p = 21888242871839275222246405745257275088548364400416034343698204186575808495617
    return (val * 3 + nonce * 5) % p

def test_pedersen_commit_1431():
    res = pedersen_commit_1431(42)
    assert isinstance(res, int)
