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
            (["48879"], "-48880"),
            (["-48880"], "48879"),
        ]
        self.check_all("01", testcases)

    def test_02(self):
        """#name(02) #score(10)"""
        testcases = [
            (["0", "0", "0", "1"], "0"),
            (["1", "2", "3", "4"], "1"),
            (["1", "3", "2", "4"], "1"),
            (["2", "1", "3", "4"], "1"),
            (["2", "3", "1", "4"], "1"),
            (["3", "1", "2", "4"], "1"),
            (["3", "2", "1", "4"], "1"),
            (["3", "2", "3", "4"], "0"),
        ]
        self.check_all("02", testcases)

    def test_03(self):
        """#name(03) #score(5)"""
        testcases = [
            ([], "0"),
            (["1"], "-1"),
            (["-1"], "1"),
            (["1", "2", "3"], "-6"),
            (["-1", "2", "-3", "4", "-5"], "3"),
        ]
        self.check_all("03", testcases)

    def test_04(self):
        """#name(04) #score(5)"""
        testcases = [
            (["0", "Hello!"], "6"),
            (["1", "Hello!"], "2"),
            (["2", "Hello!"], "1"),
        ]
        self.check_all("04", testcases)

    def test_05(self):
        """#name(05) #score(4)"""
        testcases = [
            (["hello", "h"], "0"),
            (["hello", "ll"], "2"),
            (["hello", "o"], "4"),
            (["hello", "x"], ""),
            (["helllldoworlld", "lld"], "4"),
            (["hellllolddworlld", "lld"], "13"),
            (["hellllolddworlld", "word"], ""),
            (["helldlldolddworlld", "lldd"], ""),
        ]
        self.check_all("05", testcases)

    def test_06(self):
        """#name(06) #score(10)"""
        testcases = [([], "-559038737")]
        self.check_all("06", testcases)

    def test_07(self):
        """#name(07) #score(10)"""
        testcases = [
            (["0"], "0"),
            (["7"], "1"),
            (["-3"], "-1"),
            (["48879"], "1"),
            (["-350"], "-1"),
        ]
        self.check_all("07", testcases)

    def test_08(self):
        """#name(08) #score(5)"""
        testcases = [
            ([], "0"),
            (["0", "1", "2", "3", "4", "5"], "3"),
            (["1", "0", "3", "1", "-6", "12", "-3", "-4", "0", "2"], "24"),
            (["0", "1", "-2", "1", "-4", "-3", "2", "-1"], "8"),
            (["1", "1", "-2", "1", "-4", "-4", "2", "-1"], "6"),
        ]
        self.check_all("08", testcases)

    def test_09(self):
        """#name(09) #score(5)"""
        testcases = [
            (["0", "0", "0"], "0"),
            (["0", "0", "3", "1", "-6", "12", "-3", "-4", "0", "2"], "5"),
            (["1", "0", "3", "1", "-6", "12", "-3", "-4", "0", "2"], "1"),
            (["0", "1", "-2", "1", "-4", "-3", "2", "-1"], "48"),
            (["1", "1", "-2", "1", "-4", "-3", "2", "-1"], "-48"),
        ]
        self.check_all("09", testcases)

    def test_10(self):
        """#name(10) #score(3)"""
        testcases = [
            (["hello", "h"], "0"),
            (["hello", "ll"], "2"),
            (["hello", "o"], "4"),
            (["hello", "x"], ""),
            (["helllldoworlld", "lld"], "4"),
            (["hellllolddworlld", "lld"], "13"),
            (["hellllolddworlld", "word"], ""),
            (["helldlldolddworlld", "lldd"], ""),
        ]
        self.check_all("10", testcases)

    def test_11(self):
        """#name(11) #score(10)"""
        testcases = [
            (["0"], "0"),
            (["-1"], "1"),
            (["1"], "-1"),
            (["123"], "-123"),
            (["-123"], "123"),
        ]
        self.check_all("11", testcases)

    def test_12(self):
        """#name(12) #score(10)"""
        testcases = [
            (["-5"], "0"),
            (["-1"], "0"),
            (["0"], "0"),
            (["1"], "1"),
            (["2"], "4"),
            (["3"], "9"),
            (["10"], "100"),
        ]
        self.check_all("12", testcases)

    def test_13(self):
        """#name(13) #score(5)"""
        testcases = [
            (["0", "0"], "0"),
            (["0", "1"], "0"),
            (["1", "0"], "0"),
            (["0", "-1"], "0"),
            (["-1", "0"], "0"),
            (["1", "1"], "1"),
            (["-1", "1"], "-1"),
            (["1", "-1"], "-1"),
            (["-1", "-1"], "1"),
            (["11", "7"], "77"),
            (["-3", "22"], "-66"),
            (["14", "-12"], "-168"),
            (["-10", "-11"], "110"),
        ]
        self.check_all("13", testcases)

    def test_14(self):
        """#name(14) #score(5)"""
        testcases = [
            ([], "0"),
            (["0"], "0"),
            (["1", "1", "100"], "102"),
            (["-3", "4"], "1"),
            (["-1", "-1", "-3"], "-5"),
        ]
        self.check_all("14", testcases)

    def test_15(self):
        """#name(15) #score(3)"""
        testcases = [
            ([], "0"),
            (["0", "7"], "0"),
            (["-1", "7"], "-7"),
            (["0", "-1", "2", "3", "-7", "1", "-4", "-4", "-3", "5", "3", "3"], "9"),
        ]
        self.check_all("15", testcases)
