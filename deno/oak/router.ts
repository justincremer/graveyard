import { Router } from "https://deno.land/x/oak/mod.ts";
import books from "./books.ts";

const router = new Router();

router
    .get("/", (context) => {
        context.response.body = "Home";
    })
    .get("/home", (context) => {
        context.response.body = "Home";
    })
    .get("/book", (context) => {
        context.response.body = Array.from(books.values());
    })
    .get("/book/:id", (context) => {
        if (context.params && context.params.id && books.has(context.params.id))
            context.response.body = books.get(context.params.id);
        else {
            context.response.status = 400;
            context.response.body = "Error: book not found";
        }
    });

export default router;
