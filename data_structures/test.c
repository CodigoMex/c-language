#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "queue.h"

int init_suite1(void)
{
    return 0;
}

int clean_suite1(void)
{
    return 0;
}

static void test_init_queue(void)
{
    struct Queue *queue;
    queue = init_queue();
    CU_ASSERT_PTR_NOT_NULL_FATAL(queue);
    CU_ASSERT_PTR_NULL_FATAL(queue->Head);
    CU_ASSERT_PTR_NULL_FATAL(queue->Tail);
    CU_ASSERT_EQUAL_FATAL(queue->size, 0);
    free_queue(queue);
}

int main()
{
    CU_pSuite pSuite = NULL;

    /*
     * initialize the CUnit test registry
     */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /*
     * add a suite to the registry
     */
    pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /*
     * add the tests to the suite
     */
    if (NULL ==
        CU_add_test(pSuite, "test of init_queue()", test_init_queue)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /*
     * Run all tests using the CUnit Basic interface
     */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
