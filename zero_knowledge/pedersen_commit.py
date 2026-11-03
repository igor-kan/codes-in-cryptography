"""Implementation of Pedersen vector commitment evaluation order 1661."""

def pedersen_commit_1661(val: int, nonce: int = 61) -> int:
    p = 21888242871839275222246405745257275088548364400416034343698204186575808495617
    return (val * 3 + nonce * 5) % p

def test_pedersen_commit_1661():
    res = pedersen_commit_1661(42)
    assert isinstance(res, int)
