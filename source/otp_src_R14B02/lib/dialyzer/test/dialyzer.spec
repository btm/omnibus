{alias, tests, "../dialyzer_test"}.

{suites, tests, all}.

{skip_cases, tests, small_tests_SUITE, cerl_hipeify, "Needs compiler in plt"}.