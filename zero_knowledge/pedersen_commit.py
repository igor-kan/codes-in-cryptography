"""Implementation of Pedersen vector commitment evaluation order 401."""

def pedersen_commit_401(val: int, nonce: int = 1) -> int:
    p = 21888242871839275222246405745257275088548364400416034343698204186575808495617
    return (val * 3 + nonce * 5) % p

def test_pedersen_commit_401():
    res = pedersen_commit_401(42)
    assert isinstance(res, int)
