
extern struct casio_event_log casio_event_log;
/* returns casio_event_log reference object*/
struct casio_event_log * get_casio_event_log(void);
/* initializes casio_event_log object for attributes lines and cursor and calls register_casio_event method*/
void init_casio_event_log(void);

/*this method checks event lines for memory over utilization and assigns context switch, timestamp, casio_event_log lines to 
casio event log object*/
void register_casio_event(unsigned long long t, char *m, int a);
/*
 *casio tasks and casio rq
 */
/* initializes casio_rq struct object for red black root node, casio list head ands sets running proceses to 0*/
void init_casio_rq(struct casio_rq *casio_rq);

void add_casio_task_2_list(struct casio_rq *rq, struct task_struct *p);

struct casio_task * find_casio_task_list(struct casio_rq *rq, struct task_struct *p);

void rem_casio_task_list(struct casio_rq *rq, struct task_struct *p);

void remove_casio_task_rb_tree(struct casio_rq *rq, struct casio_task *p);

/* the following inserts the casio_task p into the rb tree based on the absolute deadline 
values and does color assignment*/

void insert_casio_task_rb_tree(struct casio_rq *rq, struct casio_task *p);

/*this finds thre left most node from the rb tree to return the node with 
the  earliest deadline*/
struct casio_task * earliest_deadline_casio_task_rb_tree(struct casio_rq *rq);


/*the following checks if the current task can be prempted based on the earliest deadline value of all the  active processes in the casio rb tree
and if finds a shorted deadline , rescheduled the process.*/
static void check_preempt_curr_casio(struct rq *rq, struct task_struct *p, int flags);

/* the method identifies the next task to be scheduled based on the earliest deadline value among 
the active processes in the rb tree*/

static struct task_struct *pick_next_task_casio(struct rq *rq, struct task_struct *prev, struct rq_flags *rf);

static void enqueue_task_casio(struct rq *rq, struct task_struct *p, int flags);

static void dequeue_task_casio(struct rq *rq, struct task_struct *p, int sleep);


static void put_prev_task_casio(struct rq *rq, struct task_struct *prev);

#ifdef CONFIG_SMP
static unsigned long load_balance_casio(struct rq *this_rq, int this_cpu, struct rq *busiest,
                  unsigned long max_load_move,
                  struct sched_domain *sd, enum cpu_idle_type idle,
                  int *all_pinned, int *this_best_prio);

static int move_one_task_casio(struct task_struct *this_rq);
#endif

static void task_tick_casio(struct rq *rq, struct task_struct *p, int queued);

static void set_curr_task_casio(struct rq *rq);



/*
 * When switching a task to RT, we may overload the runqueue
 * with RT tasks. In this case we try to push them off to
 * other runqueues.
 */
static void switched_to_casio(struct rq *rq, struct task_struct *p,
                           int running);
        /*
         * If we are already running, then there's nothing
         * that needs to be done. But if we are not running
         * we may need to preempt the current running task.
         * If that current running task is also an RT task
         * then see if we can move to another run queue.
         */


unsigned int get_rr_interval_casio(struct rq *rq, struct task_struct *task);

static void yield_task_casio(struct rq *rq);


/*
 * Priority of the task has changed. This may cause
 * us to initiate a push or pull.
 */
static void prio_changed_casio(struct rq *rq, struct task_struct *p,
                            int oldprio, int running);

static int select_task_rq_casio(struct task_struct *t, int p, int sd_flag, int flags);

static void task_woken_casio(struct rq *rq, struct task_struct *p);

/*        if (!task_running(rq, p) &&
            !test_tsk_need_resched(rq->curr) &&
            has_pushable_tasks(rq) &&
            p->rt.nr_cpus_allowed > 1)
                push_rt_tasks(rq);
*/

/*
 * When switch from the rt queue, we bring ourselves to a position
 * that we might want to pull RT tasks from other runqueues.
 */
static void switched_from_casio(struct rq *rq, struct task_struct *p,
                           int running);

static const struct sched_class casio_sched_class; 
/*= {
        .next                   = &rt_sched_class,
        .enqueue_task           = enqueue_task_casio,
        .dequeue_task           = dequeue_task_casio,

        .check_preempt_curr     = check_preempt_curr_casio,

        .pick_next_task         = pick_next_task_casio,
        .put_prev_task          = put_prev_task_casio,

#ifdef CONFIG_SMP
//      .load_balance           = load_balance_casio,
        //.move_one_task                = move_one_task_casio,

        .select_task_rq         = select_task_rq_casio,
  //      .set_cpus_allowed       = set_cpus_allowed_casio,
    //    .rq_online              = rq_online_casio,
//        .rq_offline             = rq_offline_casio,
        //.pre_schedule         = pre_schedule_casio,
        //.post_schedule                = post_schedule_casio,
        .task_woken             = task_woken_casio,
        //.switched_from                = switched_from_casio,
#endif

        .set_curr_task          = set_curr_task_casio,
        .task_tick              = task_tick_casio,

        //.switched_to          = switched_to_casio,

        .yield_task             = yield_task_casio,
        .get_rr_interval        = get_rr_interval_casio,

        //.prio_changed         = prio_changed_casio,
};
*/
