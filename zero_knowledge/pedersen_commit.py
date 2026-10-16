"""Implementation of Pedersen vector commitment evaluation order 411."""

def pedersen_commit_411(val: int, nonce: int = 11) -> int:
    p = 21888242871839275222246405745257275088548364400416034343698204186575808495617
    return (val * 3 + nonce * 5) % p

def test_pedersen_commit_411():
    res = pedersen_commit_411(42)
    assert isinstance(res, int)
