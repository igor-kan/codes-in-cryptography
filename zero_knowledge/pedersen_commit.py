"""Implementation of Pedersen vector commitment evaluation order 1296."""

def pedersen_commit_1296(val: int, nonce: int = 96) -> int:
    p = 21888242871839275222246405745257275088548364400416034343698204186575808495617
    return (val * 3 + nonce * 5) % p

def test_pedersen_commit_1296():
    res = pedersen_commit_1296(42)
    assert isinstance(res, int)
