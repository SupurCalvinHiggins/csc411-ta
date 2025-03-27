import subprocess
import unittest


class TestQuestions(unittest.TestCase):
    def exec(self, num, args):
        try:
            proc = subprocess.run(
                [f"../{num}/run.sh"] + args,
                cwd="/home/rv",
                capture_output=True,
                text=True,
                check=True,
                timeout=5,
            )
            return proc.stdout.strip()
        except subprocess.TimeoutExpired:
            return "error: timeout encountered"
        except subprocess.CalledProcessError:
            return "error: nonzero return code"

    def check(self, num, args, expected_output):
        output = self.exec(num, args)
        self.assertEqual(
            output,
            expected_output,
            f"program {num} failed on execution './main {" ".join(args)}'",
        )

    def check_all(self, num, testcases):
        for args, expected_output in testcases:
            self.check(num, args, expected_output)

    def test_01(self):
        """#name(01) #score(10)"""
        testcases = [
            (["0"], "-1"),
            (["-1"], "0"),
            (["48879"], "-48879"),
            (["-48879"], "48879"),
        ]
        self.check_all("01", testcases)

    def test_02(self):
        """#name(02) #score(10)"""

    def test_03(self):
        """#name(03) #score(5)"""

    def test_04(self):
        """#name(04) #score(5)"""

    def test_05(self):
        """#name(05) #score(4)"""

    def test_06(self):
        """#name(06) #score(10)"""

    def test_07(self):
        """#name(07) #score(10)"""

    def test_08(self):
        """#name(08) #score(5)"""

    def test_09(self):
        """#name(09) #score(5)"""

    def test_10(self):
        """#name(10) #score(3)"""

    def test_11(self):
        """#name(11) #score(10)"""

    def test_12(self):
        """#name(12) #score(10)"""

    def test_13(self):
        """#name(13) #score(5)"""

    def test_14(self):
        """#name(14) #score(5)"""

    def test_15(self):
        """#name(15) #score(3)"""
