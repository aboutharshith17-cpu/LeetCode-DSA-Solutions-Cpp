#!/usr/bin/env python3
"""
Resolve placeholder folder names to the current LeetCode problem titles.

Run:
    pip install requests
    python scripts/resolve_problem_names.py

This uses LeetCode's public GraphQL problem-set endpoint.
It does NOT download or reproduce LeetCode problem statements.
"""

from pathlib import Path
import re
import requests

ROOT = Path(__file__).resolve().parent.parent
URL = "https://leetcode.com/graphql"

QUERY = """
query problemsetQuestionListV2(
    $filters: QuestionFilterInput,
    $limit: Int,
    $searchKeyword: String,
    $skip: Int,
    $sortBy: QuestionSortByInput,
    $categorySlug: String
) {
    problemsetQuestionListV2(
        filters: $filters
        limit: $limit
        searchKeyword: $searchKeyword
        skip: $skip
        sortBy: $sortBy
        categorySlug: $categorySlug
    ) {
        questions {
            title
            questionFrontendId
            titleSlug
            difficulty
            paidOnly
        }
        totalLength
    }
}
"""

def clean(title):
    title = re.sub(r"[^\w\s-]", "", title)
    title = re.sub(r"\s+", "_", title.strip())
    return title

def main():
    payload = {
        "query": QUERY,
        "variables": {
            "categorySlug": "algorithms",
            "limit": 5000,
            "skip": 0,
            "filters": {},
            "searchKeyword": ""
        }
    }

    r = requests.post(
        URL,
        json=payload,
        headers={
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0"
        },
        timeout=60
    )
    r.raise_for_status()

    data = r.json()["data"]["problemsetQuestionListV2"]["questions"]

    renamed = 0
    for q in data:
        raw_id = str(q["questionFrontendId"])
        if not raw_id.isdigit():
            continue

        number = int(raw_id)
        if number < 1 or number > 4055:
            continue

        old = ROOT / f"{number:04d}_LeetCode_Problem_{number:04d}"
        new = ROOT / f"{number:04d}_{clean(q['title'])}"

        if old.exists() and not new.exists():
            old.rename(new)
            readme = new / "README.md"
            readme.write_text(
                f"""# {number:04d} — {q['title']}

- **Difficulty:** {q.get('difficulty', 'Unknown')}
- **LeetCode:** https://leetcode.com/problems/{q['titleSlug']}/

## Approach

Write your solution approach here.

## Complexity

- **Time:** 
- **Space:** 

## Status

- [ ] C++ solution
- [ ] Explanation
- [ ] Complexity analysis
- [ ] Test cases
""",
                encoding="utf-8"
            )
            renamed += 1

    print(f"Resolved {renamed} folder names.")
    print("Existing Solution.cpp files were preserved.")

if __name__ == "__main__":
    main()
