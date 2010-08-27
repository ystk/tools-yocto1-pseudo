/* 
 * Copyright (c) 2008-2010 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * static int
 * wrap_execvp(const char *file, char *const *argv) {
 *	int rc = -1;
 */

	if (!pseudo_get_value("PSEUDO_RELOADED"))
		pseudo_setupenv();
	else {
		pseudo_setupenv();
		pseudo_dropenv();
	}

	/* if exec() fails, we may end up taking signals unexpectedly...
	 * not much we can do about that.
	 */
	sigprocmask(SIG_SETMASK, &pseudo_saved_sigmask, NULL);
	rc = real_execvp(file, argv);

/*	return rc;
 * }
 */