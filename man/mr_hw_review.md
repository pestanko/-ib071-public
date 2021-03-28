# Create a Merge Request on the FI MUNI GitLab

In order to get 0.2 KontrCoin per homework, you would need to create a 
[Merge request](https://docs.gitlab.com/ee/user/project/merge_requests/) 
on [FI MUNI GitLab](https://gitlab.fi.muni.cz/).

You would create a MR per each HW you will be submitting. 
Each MR will contain the HWXX implementation only. 
Me and Tomas will be reviewing your submissions by commenting your code directly.

It is up to you how you will create a Merge request with the submission.

## Preconditions

- add me and Tomas as `Reviewer` (or `Developer` if you want US to create MR on your behaf) to your repository (`pb071` project).
- create labels: `not-reviewed`, `reviewed`, `change-required` (a.k.a _opravit_)


## Merge Request Format

- `MR Title`: HW0X Review
- `Assignee`: Peter Stanko or Tomas Kancko
- `Reviewer`: Peter Stanko or Tomas Kancko
- `Labels`: `not-reviewed` (you need to create this)


## Possible approach to create MR

These are the steps we will be doing in order to create a Merge request:

### Create the base branch for reviews

- Create a new branch `hw-reviews` based on master

```shell
git switch -c hw-reviews
```

- [Reset](https://git-scm.com/docs/git-reset) this branch to a suitable commit - 
the one before implementing the homework or just the initial commit (better option would be the commit with the `.gitignore` file)

```shell
git log                 ## find the suitable commit hash
git reset --hard  <COMMIT_HASH>
```

- Push the new branch to your GL repository

```bash
git shell -u origin hw-reviews
```

- Switch back to the master branch

```shell
git switch master
```

### Create the branch with implementation of hwXX

- Make sure you are on the `master` branch

```shell
git switch master
```

- Create a new branch with `hwXX` submission (where `hwXX` is the specific homework, example: `hw02`)
```shell
git switch -c hwXX-review
# Example:
git switch -c hw02-review
```

- Now reset the branch's commit history to the `hw-reviews`:

```shell
git reset --mixed hw-reviews
```

- Use `git status` to make sure that you still have all your changes, but they are unstaged.
- Remove all the files that are not related to `hwXX`.
- Create a new commit with `hwXX` implementation

```shell
git add hwXX
git commit -m "Implementation of hwXX"
git push -u origin hwXX-review

# Example for hw02
git add hw02
git commit -m "Implementation of hw02"
git push -u origin hw02-review
```

After you are done, create a new MR in the UI.

- **Source branch:** `hwXX-review`
- **Target branch:** `hw-reviews`

After that you will fill in the `title` of the MR, set the `Assignee`, `Reviewer` and the `labels`.

To check whether the MR is created correctly, you should see only your `hwXX` implementation in the `Changes` tab.


## Better approach to create a MR

For each homework implementation you would create a separate branch, where you would develop the whole homework.
You would be only merging your changes to the `master` branch before submitting to kontr.

You would also need a separate branch for reviews - based on original master (before implementing and merging the `hwXX`).
After you are done with the implementation, you would create a MR with `hwXX` implementation against this branch with all your changes.

This approach is better but also it is "harder", since you would need to develop the whole HW in separate branch and branch management might become messy.

