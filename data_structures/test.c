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

static void __queue_test(struct Queue *queue)
{
    CU_ASSERT_PTR_NOT_NULL_FATAL(queue);
    CU_ASSERT_PTR_NULL_FATAL(queue->Head);
    CU_ASSERT_PTR_NULL_FATAL(queue->Tail);
    CU_ASSERT_EQUAL_FATAL(queue->size, 0);
}

// Test the correctly initialization of the queue
static void test_init_queue(void)
{
    struct Queue *queue;
    queue = init_queue();
    __queue_test(queue);
    free_queue(queue);
}

/*
 * Test that the enqueue/dequeue save and release the items and 
 * modify the size of the queue
 */
static void test_enqueue_dequeue()
{
    struct Queue *q;
    q = init_queue();
    __queue_test(q);
    struct Item *i;

    // Enqueue
    enqueue(q, 1);
    CU_ASSERT_EQUAL_FATAL(q->size, 1);

    enqueue(q, 2);
    CU_ASSERT_EQUAL_FATAL(q->size, 2);

    enqueue(q, 3);
    CU_ASSERT_EQUAL_FATAL(q->size, 3);

    enqueue(q, 4);
    CU_ASSERT_EQUAL_FATAL(q->size, 4);

    // Dequeue
    i = dequeue(q);
    CU_ASSERT_EQUAL_FATAL(i->value, 1);
    CU_ASSERT_EQUAL_FATAL(q->size, 3);
    free(i);

    i = dequeue(q);
    CU_ASSERT_EQUAL_FATAL(i->value, 2);
    CU_ASSERT_EQUAL_FATAL(q->size, 2);
    free(i);

    i = dequeue(q);
    CU_ASSERT_EQUAL_FATAL(i->value, 3);
    CU_ASSERT_EQUAL_FATAL(q->size, 1);
    free(i);

    i = dequeue(q);
    CU_ASSERT_EQUAL_FATAL(i->value, 4);
    CU_ASSERT_EQUAL_FATAL(q->size, 0);
    free(i);

    free_queue(q);
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
    if ((NULL ==
         CU_add_test(pSuite, "test of init_queue()", test_init_queue))
        || (NULL ==
            CU_add_test(pSuite, "test of enqueue() and dequeue()",
                        test_enqueue_dequeue))
        ) {
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
