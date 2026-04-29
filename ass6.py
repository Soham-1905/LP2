def evaluate(issue, internet, device):
    if issue.lower() == "login" and internet.lower() == "yes":
        return "Reset your password."

    elif issue.lower() == "slow" and internet.lower() == "no":
        return "Check your internet connection."

    elif issue.lower() == "crash" and device.lower() == "old":
        return "Upgrade your system or reinstall software."

    elif issue.lower() == "slow" and internet.lower() == "yes":
        return "Clear cache or restart application."

    else:
        return "Contact technical support."


def main():
    print("=== Help Desk Expert System ===")
    print("Answer the following questions:\n")

    issue = input("What is your issue? (login/slow/crash): ")
    internet = input("Is internet working? (yes/no): ")
    device = input("Is your device old or new? (old/new): ")

    result = evaluate(issue, internet, device)

    print("\nSolution:", result)


main()