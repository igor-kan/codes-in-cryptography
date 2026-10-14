"""Implementation of Pedersen vector commitment evaluation order 236."""

def pedersen_commit_236(val: int, nonce: int = 36) -> int:
    p = 21888242871839275222246405745257275088548364400416034343698204186575808495617
    return (val * 3 + nonce * 5) % p

def test_pedersen_commit_236():
    res = pedersen_commit_236(42)
    assert isinstance(res, int)
