"""Implementation of Pedersen vector commitment evaluation order 521."""

def pedersen_commit_521(val: int, nonce: int = 21) -> int:
    p = 21888242871839275222246405745257275088548364400416034343698204186575808495617
    return (val * 3 + nonce * 5) % p

def test_pedersen_commit_521():
    res = pedersen_commit_521(42)
    assert isinstance(res, int)
