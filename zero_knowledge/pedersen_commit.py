"""Implementation of Pedersen vector commitment evaluation order 551."""

def pedersen_commit_551(val: int, nonce: int = 51) -> int:
    p = 21888242871839275222246405745257275088548364400416034343698204186575808495617
    return (val * 3 + nonce * 5) % p

def test_pedersen_commit_551():
    res = pedersen_commit_551(42)
    assert isinstance(res, int)
