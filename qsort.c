#include "pmsis.h"


int nums[102] = {35, 39, 55, 7, 38, 24, 71, 8, 3, 42, 93, 69, 55, 7, 78, 26, 86, 93, 21, 20, 30, 32, 77, 4, 51, 53, 81, 97, 19, 7, 0, 6, 46, 56, 14, 84, 32, 85, 44, 35, 79, 89, 56, 34, 48, 34, 60, 34, 79, 33, 6, 61, 66, 35, 65, 69, 89, 98, 18, 60, 5, 19, 67, 51, 27, 81, 87, 59, 18, 31, 46, 97, 72, 2, 32, 21, 88, 44, 7, 19, 78, 66, 80, 96, 1, 46, 17, 42, 44, 35, 3, 50, 6, 22, 53, 33, 55, 93, 44, 25, 76, 42};

void swap ( int * a, int * b){
	int t = *a;
	*a = *b;
	*b = t;
}



int partition ( int arr [], int low , int high ){
	int pivot = arr [ high ];
	int i = ( low - 1);
	for ( int j = low; j <= high - 1; j ++){
		if (( arr [j] < pivot ) ? 1 : 0){
			i ++; swap (& arr[i], & arr [j ]);
		}
	}
	swap (& arr[i + 1], & arr [ high ]);
	return (i + 1);
}

void quickSort ( int arr [], int low , int high ){
	if ( low < high ){
		int pi = partition ( arr ,low , high );
		quickSort (arr , low , pi - 1);
		quickSort (arr ,pi + 1, high );
	}
}

// Function to encrypt a single character using Caesar's Cipher
char encrypt_char() {
        int n = sizeof ( nums ) / sizeof ( nums [0]);
    int i, j, count, loop;
    int digits [n][5];
    int num;
    int key = 2;
    int sum = 0;

    for (i=0; i<n ; i++) {
        for (j=0; j<5; j++)
            digits [i][j] = 0;
    }

    for (i=0; i<n; i++) {
        num = nums[i];
        count = 0;
        while (num > 0) {
            digits[i][count] = num % 10;
            sum = (digits[i][count]) + key;
            if (sum > 9) {
                digits[i][count] = sum - 9;
            }
            else{
                digits[i][count] = sum;
            }
            num /= 10;
            count++;
        }
    }
	
	// printf ("In = ");
	// for (loop=0; loop<n; loop++) printf ("%d ", nums [loop]);
	// printf("\n");

	for (i=0; i<n; i++) {
        nums [i] = (digits[i][4] * 10000) + (digits[i][3] * 1000) + (digits[i][2] * 100) + (digits[i][1] * 10) + digits[i][0];
    }

    // printf ("Out = ");	
	// for (loop=0; loop<n; loop++) printf ("%d ", nums [loop]);
	// printf("\n");
}

int main() {
	 #ifndef STATS
    //initialize performance counters
    pi_perf_conf(
        1 << PI_PERF_CYCLES | 
        1 << PI_PERF_INSTR  |
        // 1 << PI_PERF_ACTIVE_CYCLES |
        1 << PI_PERF_LD_STALL |
        // 1 << PI_PERF_JR_STALL |
        // 1 << PI_PERF_IMISS  |
        1 << PI_PERF_LD     |
        1 << PI_PERF_ST     |
        1 << PI_PERF_JUMP   |
        1 << PI_PERF_BRANCH |
        1 << PI_PERF_BTAKEN |
        1 << PI_PERF_RVC    
        // 1 << PI_PERF_LD_EXT |
        // 1 << PI_PERF_ST_EXT |
        // 1 << PI_PERF_LD_EXT_CYC |
        // 1 << PI_PERF_ST_EXT_CYC |
        // 1 << PI_PERF_TCDM_CONT
    );

    // measure statistics on matrix operations
    pi_perf_reset();
    pi_perf_start();
#else
    INIT_STATS();

    PRE_START_STATS();
    START_STATS();
#endif
	//main
    // Sort the array using quicksort
    int n = sizeof(nums) / sizeof(nums[0]);
    quickSort(nums, 0, n - 1);
    //printf("teste1\n %d\n",nums);

    // Encrypt the output using Caesar's Cipher with key=3
    int key = 3;
    for (int i = 0; i < n; i++) {
        // Print the encrypted value of the number
        //printf("%c ", encrypt_char(nums[i] + '0', key));
        encrypt_char(nums[i] + '0', key);
    }
    printf("\n");
#ifndef STATS
    pi_perf_stop();
    uint32_t instr_cnt = pi_perf_read(PI_PERF_INSTR);
    uint32_t cycles_cnt = pi_perf_read(PI_PERF_CYCLES);
    //uint32_t active_cnt = pi_perf_read(PI_PERF_ACTIVE_CYCLES);
    uint32_t ld_stall_cnt = pi_perf_read(PI_PERF_LD_STALL);
    // uint32_t jr_stall_cnt = pi_perf_read(PI_PERF_JR_STALL);
    // uint32_t cycles_imiss = pi_perf_read(PI_PERF_IMISS);
    uint32_t ld_cnt = pi_perf_read(PI_PERF_LD);
    uint32_t st_cnt= pi_perf_read(PI_PERF_ST);
    uint32_t jump_cnt= pi_perf_read(PI_PERF_JUMP);
    uint32_t branch_cnt= pi_perf_read(PI_PERF_BRANCH);
    uint32_t btaken_cnt= pi_perf_read(PI_PERF_BTAKEN);
    uint32_t rcv_cnt= pi_perf_read(PI_PERF_RVC);
    // uint32_t ld_ext_cnt= pi_perf_read(PI_PERF_LD_EXT);
    // uint32_t st_ext_cnt= pi_perf_read(PI_PERF_ST_EXT);
    // uint32_t cycles_ld_ext= pi_perf_read(PI_PERF_LD_EXT);
    // uint32_t cycles_st_ext= pi_perf_read(PI_PERF_ST_EXT);
    // uint32_t cycles_tcdm= pi_perf_read(PI_PERF_TCDM_CONT);
    printf("Number of Instructions: %d\n"
            "Clock Cycles: %d\n"
            //"CPI: %f%f\n"
            //"Number of cycles the core was active: %d\n"
            "Number of load data hazards:%d\n"
            // "Number of jump register data hazards:%d\n"
            // "Cycles waiting for instruction fetches:%d\n"
            "Number of data memory loads executed:%d\n"
            "Number of data memory stores executed:%d\n"
            "Number of unconditional jumps:%d\n"
            "Number of branches:%d\n"
            "Number of taken branches:%d\n"
            "Number of compressed instructions executed:%d\n",
            // "Number of memory loads to EXT executed:%d\n"
            // "Number of memory stores to EXT executed:%d\n"
            // "Cycles used for memory loads to EXT:%d\n"
            // "Cycles used for memory stores to EXT:%d\n"
            // "Cycles wasted due to TCDM/log-interconnect contention:%d\n",
            instr_cnt, 
            cycles_cnt, 
            //(float) cycles_cnt/instr_cnt,
            //active_cnt,
            ld_stall_cnt,
            // jr_stall_cnt,
            // cycles_imiss,
            ld_cnt,
            st_cnt,
            jump_cnt,
            branch_cnt,
            btaken_cnt,
            rcv_cnt
            // ld_ext_cnt,
            // st_ext_cnt,
            // cycles_ld_ext,
            // cycles_st_ext,
            // cycles_tcdm
            );
#else
    STOP_STATS();
#endif
    return 0;
}
