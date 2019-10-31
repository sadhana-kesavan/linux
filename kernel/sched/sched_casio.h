
extern struct casio_event_log casio_event_log;
extern const struct sched_class casio_sched_class;
extern void init_casio_event_log(void);
extern void add_casio_task_2_list(struct casio_rq *rq, struct task_struct *p);
extern void init_casio_rq(struct casio_rq *casio_rq);
