# Oauth practice with ClickUp's api

A small workspace and user enumerator for my ClickUp application.

### Setup

1. Run the openssl script in .dev/scripts (lin for unix based systems, win for windows systems)
2. Setup an api project in clickup :: Integrations -> ClickupApi -> Create an app
3. Place Client Id and Secret from clickup app in the .dev/.env.example (run `mv .env.exmaple .env` or rename)
4. Create a cookie secret in the .env

### Startup

1. cd into api/ and run `yarn start`
2. cd into client/ and run `yarn start`

### Notes

-   I've provided a client design visualization in the Documents directory (
exported as html and jpg )

#### Back

-   ✓ Connect your user via oauth (https://clickup.com/api) and store credential info in localstorage so when returning they can log out, but their session stays active locally
-   ✓ Write common team and user endpoints
-   Write list comprehensions for common team and user methods
-   Refactor (if things get too big)

#### Front

-   Get authentication header working in front end for api calls
-   Display workspaces associated with your ClickUp User, prompting you to select one
-   On Workspace selection, display the list of members that belong to the Workspace
-   Add a button that will randomly select a member
-   Display table of history for randomly selected members (store this in localstorage)
-   Add checkbox that stops the random selection from picking a same member twice (until all members have been selected at least once)
-   Animate the selection process

