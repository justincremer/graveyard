import { Application } from "https://deno.land/x/oak/mod.ts";
import router from "./router.ts";

const app = new Application();

app.use(async (context, next) => {
    await next();
    const responseTime = context.response.headers.get("X-Response-Time");
    console.log(
        `${context.request.method} ${context.request.url} ${context.response.status} - ${responseTime}`
    );
});

app.use(async (context, next) => {
    const start = Date.now();
    await next();
    const ms = Date.now() - start;
    context.response.headers.set("X-Response-Time", `${ms}ms`);
});

app.use(router.routes());
app.use(router.allowedMethods());

await app.listen({ port: 8000 });
