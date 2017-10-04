#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
	FILE * wget = NULL;
	FILE * fb2rss = NULL;
	FILE * git = NULL;
	while (1) {
		wget = popen("wget -U \"Mozzila/5.0\" \"https://www.facebook.com/1stawesomeplatoon/posts\" -Oposts.html", "r");
		if (!wget) {
			fprintf(stderr, "error: wget isn't available\n");
			return 0;
		}
		pclose(wget);

		fb2rss = popen("fb2rss posts.html -oposts.xml", "r");
		if (!fb2rss) {
			fprintf(stderr, "error: fb2rss isn't available\n");
			return 0;
		}
		pclose(fb2rss);

		git = popen("git commit -a", "r");
		if (!git) {
			fprintf(stderr, "error: git isn't available\n");
			return 0;
		}
		pclose(git);

		git = popen("git push", "r");
		if (!git) {
			fprintf(stderr, "error: git isn't available\n");
			return 0;
		}
		pclose(git);

		usleep(60*1000000);
	}

	return 0;
}
